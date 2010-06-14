/*	$NetBSD: rpm2pkg.c,v 1.10 2010/06/14 11:24:48 tron Exp $	*/

/*-
 * Copyright (c) 2004-2009 The NetBSD Foundation, Inc.
 * All rights reserved.
 *
 * This code is derived from software contributed to The NetBSD Foundation
 * by Matthias Scheler.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
 * ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include <sys/types.h>
#include <sys/stat.h>

#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <bzlib.h>
#include <zlib.h>

/*
 * Lead of an RPM archive as described here:
 * http://www.rpm.org/max-rpm/s1-rpm-file-format-rpm-file-format.html
 */
static const unsigned char RPMMagic[] = { 0xed, 0xab, 0xee, 0xdb };

#define	RPM_LEAD_SIZE	96

/* Magic bytes for "bzip2" and "gzip" compressed files. */
static const unsigned char BZipMagic[] = { 'B', 'Z', 'h' };
static const unsigned char GZipMagic[] = { 0x1f, 0x8b, 0x08 };

/* Structure of a cpio(1) archive. */
#define C_IRUSR			0000400
#define C_IWUSR			0000200
#define C_IXUSR			0000100
#define C_IRGRP			0000040
#define C_IWGRP			0000020
#define C_IXGRP			0000010
#define C_IROTH			0000004
#define C_IWOTH			0000002
#define C_IXOTH			0000001
#define C_ISUID			0004000
#define C_ISGID			0002000
#define C_ISVTX			0001000
#define C_ISDIR			0040000
#define C_ISREG			0100000
#define C_ISCHR			0020000
#define C_ISLNK			0120000
 
static const unsigned char CPIOMagic[] = {'0','7','0','7','0','1'};

#define CPIO_END_MARKER		"TRAILER!!!"
#define CPIO_FIELD_LENGTH	8

#define CPIO_HDR_INODE		0
#define CPIO_HDR_MODE		1
#define CPIO_HDR_FILESIZE	6
#define CPIO_HDR_NAMESIZE	11
#define CPIO_NUM_HEADERS	13

#define CP_IFMT			0170000

typedef struct ModeMapStruct {
	unsigned long	mm_CPIOMode;
	mode_t		mm_SysMode;
} ModeMap;

ModeMap ModeMapTab[] = {
	{C_IRUSR, S_IRUSR},
	{C_IWUSR, S_IWUSR},
	{C_IXUSR, S_IXUSR},
	{C_IRGRP, S_IRGRP},
	{C_IWGRP, S_IWGRP},
	{C_IXGRP, S_IXGRP},
	{C_IROTH, S_IROTH},
	{C_IWOTH, S_IWOTH},
	{C_IXOTH, S_IXOTH},
	{C_ISUID, S_ISUID},
	{C_ISGID, S_ISGID},
	{C_ISVTX, S_ISVTX},
	{0, 0}
};

typedef struct PListEntryStruct PListEntry;
struct PListEntryStruct {
	PListEntry	*pe_Childs[2];
	int		pe_DirEmpty;
	mode_t		pe_DirMode;
	unsigned long	pe_INode;
	char		*pe_Link;
	char		pe_Name[1];
};

#define	pe_Left		pe_Childs[0]
#define	pe_Right	pe_Childs[1]

typedef void PListEntryFunc(PListEntry *,FILE *);

#define	PLIST_ORDER_FORWARD	0
#define	PLIST_ORDER_BACKWARD	1

#define INVERT_PLIST_ORDER(o)	(1 - (o))

typedef struct FileHandleStruct {
	FILE	*fh_File;
	BZFILE	*fh_BZFile;
	gzFile	*fh_GZFile;
	off_t	fh_Pos;
} FileHandle;

static bool
InitBuffer(void **Buffer, size_t *BufferSizePtr)
{
	if (*Buffer == NULL) {
		size_t BufferSize;

		BufferSize = sysconf(_SC_PAGESIZE) * 256;
		while ((*Buffer = malloc(BufferSize)) == NULL) {
			BufferSize >>= 1;
			if (BufferSize == 0)
				return false;
		}
		*BufferSizePtr = BufferSize;
	}
	return true;
}

static void
Close(FileHandle *fh)
{
	if (fh->fh_BZFile != NULL) {
		int	bzerror;

		(void)BZ2_bzReadClose(&bzerror, fh->fh_BZFile);
		(void)fclose(fh->fh_File);
	} else {
		(void)gzclose(fh->fh_GZFile);
	}
	free(fh);
}

static bool
IsRPMFile(int fd)
{
	char buffer[RPM_LEAD_SIZE];

	if (read(fd, buffer, sizeof(buffer)) != sizeof(buffer))
		return false;

	return (memcmp(buffer, RPMMagic, sizeof(RPMMagic)) == 0);
}

static FileHandle *
Open(int fd)
{
	unsigned char	buffer[16384];
	size_t		bzMatch, gzMatch;
	int		archive_type;
	off_t		offset;
	FileHandle	*fh;

	bzMatch = 0;
	gzMatch = 0;
	archive_type = 0;
	offset = 0;
	do {
		ssize_t	bytes, i;

		bytes = read(fd, buffer, sizeof(buffer));
		if (bytes <= 0)
			return NULL;

		for (i = 0; i < bytes; i++) {
			unsigned char cur_char;

			cur_char = buffer[i];

			/* Look for bzip2 header. */
			if (cur_char == BZipMagic[bzMatch]) {
				bzMatch++;
				if (bzMatch == sizeof(BZipMagic)) {
					archive_type = 1;
					offset = i - bytes -
					    sizeof(BZipMagic) + 1;
					break;
				}
			} else {
				bzMatch = (cur_char == BZipMagic[0]) ? 1 : 0;
			}

			/* Look for gzip header. */
			if (cur_char == GZipMagic[gzMatch]) {
				gzMatch++;
				if (gzMatch == sizeof(GZipMagic)) {
					archive_type = 2;
					offset = i - bytes -
					    sizeof(GZipMagic) + 1;
					break;
				}
			} else {
				gzMatch = (cur_char == GZipMagic[0]) ? 1 : 0;
			}
		}
	} while (archive_type == 0);

	/* Go back to the beginning of the archive. */
	if (lseek(fd, offset, SEEK_CUR) < RPM_LEAD_SIZE)
		return NULL;

	if ((fh = calloc(1, sizeof (FileHandle))) == NULL)
		return NULL;

	if (archive_type == 1) {
		/* bzip2 archive */
		int	bzerror;

		if ((fd = dup(fd)) < 0) {
			free(fh);
			return NULL;
		}
		if ((fh->fh_File = fdopen(fd, "rb")) == NULL) {
			perror("fdopen");
			(void)close(fd);
			free(fh);
			return NULL;
		}
		if ((fh->fh_BZFile = BZ2_bzReadOpen(&bzerror, fh->fh_File, 0,
		    0, NULL, 0)) == NULL) {
			(void)fclose(fh->fh_File);
			free(fh);
			return (NULL);
		}
	} else {
		/* gzip archive */
		if ((fh->fh_GZFile = gzdopen(fd, "r")) == NULL) {
			free(fh);
			return (NULL);
		}
	}

	return (fh);
}

static int
Read(FileHandle *fh, void *buffer, int length)
{
	int	bzerror, bytes;

	bytes = (fh->fh_BZFile != NULL) ?
	    BZ2_bzRead(&bzerror, fh->fh_BZFile, buffer, length) :
	    gzread(fh->fh_GZFile, buffer, length);
	if (bytes > 0)
		fh->fh_Pos += bytes;

	return (bytes == length);
}

static bool
SkipAndAlign(FileHandle *fh, off_t Skip)

{
	off_t		NewPos;

	NewPos = (fh->fh_Pos + Skip + 3) & ~3;
	if (fh->fh_Pos == NewPos)
		return true;

	if (fh->fh_GZFile != NULL) {
		if (gzseek(fh->fh_GZFile, NewPos, SEEK_SET) == NewPos) {
			fh->fh_Pos = NewPos;
			return true;
		}
		return false;
	} else {
		static void	*Buffer = NULL;
		static size_t	BufferSize = 0;

		if (!InitBuffer(&Buffer, &BufferSize))
			return false;

		while (fh->fh_Pos < NewPos) {
			off_t	Length;
			int	Chunk;

			Length = NewPos - fh->fh_Pos;
			Chunk = (Length > (off_t)BufferSize) ?
			    (off_t)BufferSize : Length;
			if (!Read(fh, Buffer, Chunk))
				return false;
		}
	}

	return true;
}

static PListEntry *
InsertPListEntry(PListEntry **Tree,char *Name)
{
	PListEntry *Node;

	while ((Node = *Tree) != NULL) {
		Tree = (strcmp(Name, Node->pe_Name) <0) ?
		    &Node->pe_Left : &Node->pe_Right;
	}

	if ((Node = calloc(1, sizeof (PListEntry) + strlen(Name))) == NULL) {
		perror("calloc");
		exit(EXIT_FAILURE);
	}

	(void)strcpy(Node->pe_Name, Name);

	return *Tree = Node;
}

static PListEntry *
FindPListEntry(PListEntry *Tree, char *Name)
{
	while (Tree != NULL) {
		int Result;

		if ((Result = strcmp(Name, Tree->pe_Name)) == 0) break;
		Tree = (Result < 0) ? Tree->pe_Left : Tree->pe_Right;
	}

	return Tree;
}

static void
PListEntryFile(PListEntry *Node, FILE *Out)

{
	(void)fputs(Node->pe_Name, Out);
	(void)fputc('\n', Out);
}

static char *
StrCat(char *Prefix, char *Suffix)
{
	int	Length;
	char	*Str;

	Length = strlen(Prefix);
	if ((Str = malloc(Length + strlen(Suffix) + 1)) == NULL) {
	     perror("malloc");
	     exit(EXIT_FAILURE);
	}

	(void)memcpy(Str, Prefix, Length);
	(void)strcpy(&Str[Length], Suffix);

	return Str;
}

static void
PListEntryLink(PListEntry *Node, FILE *Out)

{
	char		*Ptr;
	struct stat	Stat;
	int		Result;

	if ((Ptr = strrchr(Node->pe_Name, '/')) != NULL) {
		char	Old, *Targetname;

		Old = Ptr[1];
		Ptr[1] = '\0';
		Targetname = StrCat(Node->pe_Name, Node->pe_Link);
		Ptr[1] = Old;

		Result = stat(Targetname, &Stat);
		free(Targetname);
	} else {
		Result = stat(Node->pe_Link, &Stat);
	}

	if ((Result == 0) && ((Stat.st_mode & S_IFMT) == S_IFREG)) {
		PListEntryFile(Node, Out);
		return;
	}

	(void)fprintf(Out, "@exec ln -fs %s %%D/%s\n@unexec rm -f %%D/%s\n",
	    Node->pe_Link, Node->pe_Name, Node->pe_Name);
}

static void
PListEntryMakeDir(PListEntry *Node, FILE *Out)

{
	if (Node->pe_DirEmpty) {
		(void)fprintf(Out, "@exec mkdir -m %o -p %%D/%s\n",
		     Node->pe_DirMode, Node->pe_Name);
	}
}

static void
ProcessPList(PListEntry *Tree, PListEntryFunc Func, int Order, FILE *Out)

{
	while (Tree != NULL) {
		if (Tree->pe_Childs[Order] != NULL)
			ProcessPList(Tree->pe_Childs[Order], Func, Order, Out);
		Func(Tree, Out);
		Tree = Tree->pe_Childs[INVERT_PLIST_ORDER(Order)];
	}
}

static char **
ArrayAdd(char **Array, char *String)

{
	int	Old;

	Old = 0;
	if (Array != NULL) {
		while (Array[Old] != NULL)
			Old ++;
	}
	if ((Array = realloc(Array, sizeof (char *) * (Old + 2))) == NULL) {
		perror("realloc");
		exit(EXIT_FAILURE);
	}

	Array[Old++] = String;
	Array[Old] = NULL;

	return Array;
}

static void
Usage(char *Progname)
{
	(void)fprintf(stderr, 
	    "Usage: %s [-d directory] [-f packlist] [[-i ignorepath] ...]\n"
	    "               [-p prefix] [-s stripcount] rpmfile [...]\n", 
	    Progname);
	exit(EXIT_FAILURE);
}

static char *
GetData(FileHandle *In, unsigned long Length)
{
	char *Ptr;

	if ((Ptr = malloc(Length + 1)) != NULL) {
		if (Read(In, Ptr, Length) && SkipAndAlign(In, 0)) {
			Ptr[Length] = '\0';
			return Ptr;
		}
		free(Ptr);
	}

	return NULL;
}

static bool
GetCPIOHeader(FileHandle *In, unsigned long *Fields, char **Name)
{
	char	Buffer[CPIO_NUM_HEADERS * CPIO_FIELD_LENGTH], *Ptr;
	int	Index;
	unsigned long	Value;

	*Name = NULL;

	if (!Read(In, Buffer, sizeof (CPIOMagic)))
		return false;
	if (memcmp(Buffer, CPIOMagic, sizeof (CPIOMagic)) != 0)
		return false;

	if (!Read(In, Buffer, sizeof (Buffer)))
		return false;

	Ptr = Buffer;
	Index = sizeof (Buffer);
	Value = 0;
	while (Index-- > 0) {
		Value <<= 4;
		if ((*Ptr >= '0') && (*Ptr <= '9')) {
			Value += (unsigned long)(*Ptr++-'0');
		} else if ((*Ptr >= 'A') && (*Ptr <= 'F')) {
				Value += (unsigned long)(*Ptr++-'A') + 10;
		} else if ((*Ptr >= 'a') && (*Ptr <= 'f')) {
				Value += (unsigned long)(*Ptr++-'a') + 10;
		} else {
			return false;
		}
   
		if ((Index % CPIO_FIELD_LENGTH) == 0) {
			*Fields++ = Value;
			Value = 0;
		}
  	}

	Value = Fields[CPIO_HDR_NAMESIZE - CPIO_NUM_HEADERS];
	if ((*Name = GetData(In, Value)) == NULL)
		return false;
	return ((*Name)[Value -1 ] == '\0');
}

static mode_t
ConvertMode(unsigned long CPIOMode)
{
	mode_t	Mode;
	ModeMap	*Ptr;

	Mode = 0;
	Ptr = ModeMapTab;
	while (Ptr->mm_CPIOMode != 0) {
		if ((CPIOMode & Ptr->mm_CPIOMode) != 0)
			Mode |= Ptr->mm_SysMode;
		Ptr++;
	}

	return Mode;
}

static bool
MakeTargetDir(char *Name, PListEntry **Dirs, int MarkNonEmpty)
{
	char		*Basename;
	PListEntry	*Dir;
	struct stat	Stat;
	int	Result;

	if ((Basename = strrchr(Name, '/')) == NULL)
		return true;

	*Basename = '\0';
	if ((Dir = FindPListEntry(*Dirs, Name)) != NULL) {
		*Basename = '/';
		Dir->pe_DirEmpty = !MarkNonEmpty;
		return true;
	}

	if (!MakeTargetDir(Name, Dirs, true)) {
		*Basename = '/';
		return false;
	}

	if (stat(Name, &Stat) == 0) {
		Result = S_ISDIR(Stat.st_mode);
	} else if (errno != ENOENT) {
		Result = false;
	} else if ((Result = (mkdir(Name, S_IRWXU|S_IRWXG|S_IRWXO) == 0))) {
		InsertPListEntry(Dirs, Name)->pe_DirMode =
		    S_IRWXU|S_IRWXG|S_IRWXO;
	}

	*Basename = '/';
	return Result;
}

static bool
MakeDir(char *Name, mode_t Mode, int *OldDir)
{
	struct stat Stat;

	*OldDir = false;
	if (mkdir(Name, Mode) == 0)
		return true;

	if ((errno != EEXIST) || (lstat(Name, &Stat) < 0) || 
	    !S_ISDIR(Stat.st_mode)) {
		return false;
	}

	*OldDir = true;
	return true;
}

static bool
MakeSymLink(char *Link, char *Name)
{
	struct stat Stat;

	if (symlink(Link, Name) == 0) return true;

	if ((errno != EEXIST) || (lstat(Name, &Stat) < 0) || 
	    !S_ISLNK(Stat.st_mode)) {
		return false;
	}

	return ((unlink(Name) == 0) && (symlink(Link, Name) == 0));
}

static bool
WriteFile(FileHandle *In, char *Name, mode_t Mode, unsigned long Length,
    char *Link)
{
	int		Out;
	struct stat	Stat;
	static void	*Buffer = NULL;
	static size_t	BufferSize = 0;

	if ((lstat(Name, &Stat) == 0) &&
	    (!S_ISREG(Stat.st_mode) || (unlink(Name) < 0))) {
		return false;
	}

	if (!InitBuffer(&Buffer, &BufferSize))
		return false;

	if (Link != NULL) {
		if (link(Link, Name) < 0)
			return false;
		Out = open(Name, O_WRONLY, Mode);
	 } else {
		Out = open(Name, O_WRONLY|O_CREAT, Mode);
	}
	if (Out < 0)
		return false;

	while (Length > 0) {
		int	Chunk;

		Chunk = (Length > BufferSize) ? BufferSize : Length;
		if (!Read(In, Buffer, Chunk) ||
		    (write(Out, Buffer, Chunk) != Chunk))
			break;
		Length -= Chunk;
	}

	if ((close(Out) == 0) && (Length == 0))
		return SkipAndAlign(In, 0);

	(void)unlink(Name);
	return false;
}

static void
CheckSymLinks(PListEntry **Links, PListEntry **Files, PListEntry **Dirs)
{
	PListEntry	*Link;

	while ((Link = *Links) != NULL) {
		struct stat	Stat;
		PListEntry	*Ptr;
		char		*Basename;

		if (Link->pe_Left != NULL)
			CheckSymLinks(&Link->pe_Left, Files, Dirs);

		if ((stat(Link->pe_Name, &Stat) < 0) ||
		    !S_ISREG(Stat.st_mode)) {
			Links = &Link->pe_Right;
			continue;
		}

		(void)InsertPListEntry(Files, Link->pe_Name);
		if ((Basename = strrchr(Link->pe_Name, '/')) != NULL) {
			*Basename = '\0';
			if ((Ptr = FindPListEntry(*Dirs,
			    Link->pe_Name)) != NULL)
				Ptr->pe_DirEmpty = false;
		}

		if (Link->pe_Right == NULL) {
			*Links = Link->pe_Left;
			free(Link);
			break;
		}

		*Links = Link->pe_Right;
		Ptr = Link->pe_Left;
		free(Link);

		if (Ptr == NULL)
			continue;

		Link = *Links;
		while (Link->pe_Left != NULL)
			Link = Link->pe_Left;
		Link->pe_Left = Ptr;
	}
}

static bool
CheckPrefix(char *Prefix, char *Name)
{
	int	Length;

	Length = strlen(Prefix);
	return ((strncmp(Prefix, Name, Length) == 0) && 
	    ((Name[Length] == '\0') || (Name[Length] == '/')));
}

static char *
StripPrefix(char *Name, int Count)
{
	char *NewName;

	if (Count <= 0)
		return Name;

	NewName = Name;
	while (Count-- > 0) {
		NewName = strchr(NewName, '/');
		if (NewName == NULL)
			return NULL;
		NewName++;
	}
	(void)memmove(Name, NewName, strlen(NewName) + 1);

	return Name;
}

int
main(int argc, char **argv)
{
	char		*Progname;
	FILE		*PListFile;
	char		**Ignore, *Prefix;
	int		Opt, Index, FD, StripCount;
	PListEntry	*Files, *Links, *Dirs;
	FileHandle	*In;

	Progname = strrchr(argv[0], '/');
	if (Progname == NULL)
		Progname = argv[0];
	else
		Progname ++;

	PListFile = NULL;
	Ignore = NULL;
	Prefix = NULL;
	StripCount = 0;
	while ((Opt = getopt(argc, argv, "s:d:f:i:p:")) != -1) {
		switch (Opt) {
		case 's':
			StripCount = atoi(optarg);
			if (StripCount <= 0) {
     				(void)fprintf(stderr,
				    "%s: -s argument \"%s\" "
				    "must be a positive integer.\n",
				    Progname, optarg);
				return EXIT_FAILURE;
    			}
			break;
		case 'f':
			if (PListFile != NULL)
				(void)fclose(PListFile);
			if ((PListFile = fopen(optarg, "a")) == NULL) {
				perror(optarg);
				return EXIT_FAILURE;
			}
			break;
		case 'i':
			Ignore = ArrayAdd(Ignore, optarg);
			break;
		case 'd':
			if (chdir(optarg)) {
				perror(optarg);
				return EXIT_FAILURE;
			}
			break;
		case 'p':
			if (strlen(optarg) > 0)
				Prefix = optarg;
			break;
		default:
			Usage(Progname);
		}
	}

	argc -= optind;
	argv += optind;
	if (argc == 0)
		Usage(Progname);

	if ((Prefix != NULL) && (Prefix[strlen(Prefix) - 1] != '/'))
		Prefix = StrCat(Prefix, "/");

	Files = NULL;
	Links = NULL;
	Dirs = NULL;
	for (Index = 0; Index < argc ; Index++) {
		PListEntry	*Last;

		if ((FD = open(argv[Index], O_RDONLY, 0)) < 0) {
			perror(argv[Index]);
			return EXIT_FAILURE;
		}

		if (!IsRPMFile(FD)) {
			(void)fprintf(stderr,
			    "%s: file is not an RPM package.\n", argv[Index]);
			return EXIT_FAILURE;
		}

		if ((In = Open(FD)) == NULL) {
			(void)fprintf(stderr,
			    "%s: cannot read cpio data.\n", argv[Index]);
			return EXIT_FAILURE;
		}

		Last = NULL;
		for (;;) {
			unsigned long	Fields[CPIO_NUM_HEADERS];
			char		*Name;
			mode_t		Mode;
			unsigned long Length;

			if (!GetCPIOHeader(In, Fields, &Name)) {
				(void)fprintf(stderr,
				    "%s: error in cpio header.\n",
				    argv[Index]);
				return EXIT_FAILURE;
			}
			if (strcmp(Name, CPIO_END_MARKER) == 0) {
				free(Name);
				break;
			}
			if (*Name == '\0')
				Fields[CPIO_HDR_MODE] = 0;

			if (Ignore != NULL) {
				char **Ptr;

				Ptr = Ignore;
				while (*Ptr != NULL) {
					if (CheckPrefix(*Ptr, Name)) {
						Fields[CPIO_HDR_MODE] = 0;
						break;
					}
					Ptr++;
				}
			}

			if ((Name = StripPrefix(Name, StripCount)) == NULL) {
				(void)fprintf(stderr,
					    "%s: Leading path to strip too "
					    "big (-s %d)\n", 
					    argv[Index], StripCount);
				return EXIT_FAILURE;
			}

			if (Prefix != NULL) {
				char *Fullname;

			  	Fullname = StrCat(Prefix, Name);
				free(Name);
				Name = Fullname;
			}

			Mode = ConvertMode(Fields[CPIO_HDR_MODE]);
			Length = Fields[CPIO_HDR_FILESIZE];
			switch (Fields[CPIO_HDR_MODE] & CP_IFMT) {
			case C_ISDIR: {
				PListEntry	*Dir;
				int		OldDir;

				if (Length != 0) {
					(void)fprintf(stderr,
					    "%s: error in cpio file.\n",
					argv[Index]);
					return EXIT_FAILURE;
				}

				if (!MakeTargetDir(Name, &Dirs, true)) {
					(void)fprintf(stderr, 
					    "%s: can't create parent "
					    "directories for \"%s\".\n", 
			                    argv[Index], Name);
					return EXIT_FAILURE;
				}

				if (!MakeDir(Name, Mode, &OldDir)) {
					(void)fprintf(stderr, 
					    "%s: can't create directory "
					    "\"%s\".\n", argv[Index], Name);
					return EXIT_FAILURE;
				}

				if (!OldDir) {
					Dir = InsertPListEntry(&Dirs, Name);
					Dir->pe_DirEmpty = true;
					Dir->pe_DirMode = Mode;
				}
				break;
			}
			case C_ISLNK: {
				char	*Link;

				if ((Link = GetData(In, Length)) == NULL) {
					(void)fprintf(stderr,
					    "%s: error in cpio file.\n",
					argv[Index]);
					return EXIT_FAILURE;
				}

				if (!MakeTargetDir(Name, &Dirs, true)) {
					(void)fprintf(stderr, 
					    "%s: can't create parent "
					    "directories for \"%s\".\n", 
			                    argv[Index], Name);
					return EXIT_FAILURE;
				}

				if (*Link == '/') {
					char	*Ptr;

					(void)memmove(Link, Link + 1,
					    strlen(Link + 1) + 1);
					Ptr = Name;
					if (Prefix != NULL)
						Ptr += strlen(Prefix);

					while ((Ptr = strchr(Ptr, '/'))
					    != NULL) {
						char *NewLink;

					    	NewLink = StrCat("../", Link);
						free(Link);
						Link = NewLink;
						Ptr++;
					}
				}

				if (!MakeSymLink(Link, Name)) {
					(void)fprintf(stderr, 
					    "%s: can't create symbolic link "
					    "\"%s\".\n", argv[Index], Name);
					return EXIT_FAILURE;
				}

		    		InsertPListEntry(&Links, Name)->pe_Link = Link;
				break;
			}
			case C_ISREG:
				if (!MakeTargetDir(Name, &Dirs, true)) {
					(void)fprintf(stderr, 
					    "%s: can't create parent "
					    "directories for \"%s\".\n", 
			                    argv[Index], Name);
					return EXIT_FAILURE;
				}


				if ((Last != NULL) && (Last->pe_INode != 
				    Fields[CPIO_HDR_INODE])) {
					Last = NULL;
				}

				if (!WriteFile(In, Name, Mode, Length,
				    (Last != NULL)? Last->pe_Name : NULL)) {
					(void)fprintf(stderr, 
			                    "%s: can't write file \"%s\".\n", 
			                    argv[Index], 
			                    Name);
					return EXIT_FAILURE;
				}

				Last = InsertPListEntry(&Files, Name);
				Last->pe_INode = Fields[CPIO_HDR_INODE];
				break;
			default:
				if ((Length > 0) &&
				    !SkipAndAlign(In, Length)) {
					(void)fprintf(stderr,
					    "%s: error in cpio file.\n",
					    argv[Index]);
					return EXIT_FAILURE;
				}
						
			}

			free(Name);
		}

		Close(In);
		(void)close(FD);
	}

	if (PListFile != NULL) {
		ProcessPList(Files, PListEntryFile, PLIST_ORDER_FORWARD,
		    PListFile);
		ProcessPList(Dirs, PListEntryMakeDir, PLIST_ORDER_FORWARD,
		    PListFile);
		ProcessPList(Links, PListEntryLink, PLIST_ORDER_FORWARD,
		    PListFile);
		(void)fclose(PListFile);
	}

	return EXIT_SUCCESS;
}
