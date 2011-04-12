/*	$NetBSD: rpm2pkg.c,v 1.21 2011/04/12 22:12:42 tron Exp $	*/

/*-
 * Copyright (c) 2001-2011 The NetBSD Foundation, Inc.
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

#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "fileio.h"
#include "package-list.h"
#include "parse-rpm.h"

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

static bool
SkipAndAlign(FileHandle *fh, off_t skip)
{
	off_t old_pos, new_pos;
	char buffer[1 << 16];

	old_pos = FileHandleGetPos(fh);
	new_pos = (old_pos + skip + 3) & ~3;
	if (old_pos == new_pos)
		return true;

	while (old_pos < new_pos) {
		off_t length;
		size_t chunk;

		length = new_pos - old_pos;
		chunk = (length > (off_t)sizeof(buffer)) ?
		    (off_t)sizeof(buffer) : length;
		if (!FileHandleRead(fh, buffer, chunk))
			return false;

		old_pos = FileHandleGetPos(fh);
	}

	return true;
}

static char *
StrCat(const char *prefix, const char *suffix)
{
	size_t	prefix_length;
	char	*str;

	prefix_length = strlen(prefix);
	if ((str = malloc(prefix_length + strlen(suffix) + 1)) == NULL) {
	     perror("malloc");
	     exit(EXIT_FAILURE);
	}

	(void)memcpy(str, prefix, prefix_length);
	(void)strcpy(&str[prefix_length], suffix);

	return str;
}

static char **
ArrayAdd(char **array, char *string)
{
	size_t old;

	old = 0;
	if (array != NULL) {
		while (array[old] != NULL)
			old++;
	}

	if ((array = realloc(array, sizeof(char *) * (old + 2))) == NULL) {
		perror("realloc");
		exit(EXIT_FAILURE);
	}

	array[old++] = string;
	array[old] = NULL;

	return array;
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
		if (FileHandleRead(In, Ptr, Length) && SkipAndAlign(In, 0)) {
			Ptr[Length] = '\0';
			return Ptr;
		}
		free(Ptr);
	}

	return NULL;
}

static bool
GetCPIOHeader(FileHandle *in, unsigned long *fields, char **name)
{
	char		buffer[CPIO_NUM_HEADERS][CPIO_FIELD_LENGTH];
	char		header[CPIO_FIELD_LENGTH + 1];
	size_t		i, j;
	unsigned long	namelen;

	*name = NULL;

	if (!FileHandleRead(in, buffer, sizeof(CPIOMagic)))
		return false;
	if (memcmp(buffer, CPIOMagic, sizeof(CPIOMagic)) != 0)
		return false;

	if (!FileHandleRead(in, buffer, sizeof(buffer)))
		return false;

	header[CPIO_FIELD_LENGTH] = '\0';
	for (i = 0; i < CPIO_NUM_HEADERS; i++) {
		for (j = 0; j < CPIO_FIELD_LENGTH; j++) {
			if (!isxdigit((unsigned char)buffer[i][j]))
				return false;
			header[j] = buffer[i][j];
		}

		fields[i] = strtoul(header, NULL, 16);
	}

	namelen = fields[CPIO_HDR_NAMESIZE];
	if ((*name = GetData(in, namelen)) == NULL)
		return false;
	return ((*name)[namelen - 1] == '\0');
}

static mode_t
ConvertMode(unsigned long cpio_mode)
{
	mode_t	mode;
	ModeMap	*ptr;

	for (ptr = ModeMapTab, mode = 0; ptr->mm_CPIOMode != 0; ptr++) {
		if (cpio_mode & ptr->mm_CPIOMode)
			mode |= ptr->mm_SysMode;
	}

	return mode;
}

static bool
MakeTargetDir(char *Name, PListEntry **Dirs)
{
	char		*Basename;
	PListEntry	*Dir;
	struct stat	Stat;
	int	Result;

	if ((Basename = strrchr(Name, '/')) == NULL)
		return true;

	*Basename = '\0';
	if ((Dir = PListFind(*Dirs, Name)) != NULL) {
		*Basename = '/';
		Dir->pe_DirEmpty = false;
		return true;
	}

	if (!MakeTargetDir(Name, Dirs)) {
		*Basename = '/';
		return false;
	}

	if (stat(Name, &Stat) == 0) {
		Result = S_ISDIR(Stat.st_mode);
	} else if (errno != ENOENT) {
		Result = false;
	} else if ((Result = (mkdir(Name, S_IRWXU|S_IRWXG|S_IRWXO) == 0))) {
		(void)PListInsert(Dirs, Name);
	}

	*Basename = '/';
	return Result;
}

static bool
MakeDir(char *name, mode_t mode, bool *old_dir)
{
	struct stat sb;

	*old_dir = false;
	if (mkdir(name, mode) == 0)
		return true;

	if (errno != EEXIST || lstat(name, &sb) < 0 || !S_ISDIR(sb.st_mode))
		return false;

	*old_dir = true;
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
WriteFile(FileHandle *in, char *name, mode_t mode, unsigned long length,
    const char *link_target)
{
	int		outfd;
	struct stat	sb;
	char		buffer[1 << 16];

	if ((lstat(name, &sb) == 0) &&
	    (!S_ISREG(sb.st_mode) || (unlink(name) < 0))) {
		return false;
	}

	if (link_target != NULL) {
		if (link(link_target, name) < 0)
			return false;
		outfd = open(name, O_WRONLY, mode);
	 } else {
		outfd = open(name, O_WRONLY|O_CREAT, mode);
	}
	if (outfd < 0)
		return false;

	while (length > 0) {
		ssize_t	chunk;

		chunk = (length > sizeof(buffer)) ? sizeof(buffer) : length;
		if (!FileHandleRead(in, buffer, chunk) ||
		    write(outfd, buffer, chunk) != chunk)
			break;
		length -= chunk;
	}

	if (close(outfd) == 0 && length == 0)
		return SkipAndAlign(in, 0);

	(void)unlink(name);
	return false;
}

static bool
CheckPrefix(const char *prefix, char *name)
{
	size_t length;

	length = strlen(prefix);
	return ((strncmp(prefix, name, length) == 0) &&
	    ((name[length] == '\0') || (name[length] == '/')));
}

static bool
StripPrefix(char *name, int stripcount)
{
	char *new_name;

	if (stripcount <= 0)
		return true;

	new_name = name;
	while (stripcount-- > 0) {
		new_name = strchr(new_name, '/');
		if (new_name == NULL)
			return false;
		new_name++;
	}
	(void)memmove(name, new_name, strlen(new_name) + 1);

	return true;
}

static void
ProcessRPM(const char *filename, PListEntry **files, PListEntry **dirs,
    char **ignore, const char *prefix, int stripcount)
{
	int		fd;
	FileHandle	*in;
	PListEntry	*last;

	if ((fd = open(filename, O_RDONLY, 0)) < 0) {
		perror(filename);
		exit(EXIT_FAILURE);
	}

	if (!IsRPMFile(fd)) {
		(void)fprintf(stderr, "%s: file is not an RPM package.\n",
		    filename);
		exit(EXIT_FAILURE);
	}

	if ((in = OpenRPM(&fd)) == NULL) {
		(void)fprintf(stderr, "%s: cannot get RPM data.\n", filename);
		exit(EXIT_FAILURE);
	}
	if (fd >= 0) {
		(void)close(fd);
		fd = -1;
	}

	last = NULL;
	for (;;) {
		unsigned long	fields[CPIO_NUM_HEADERS];
		char		*name;
		mode_t		mode;
		unsigned long	length;

		if (!GetCPIOHeader(in, fields, &name)) {
			(void)fprintf(stderr,
			    "%s: error in cpio header.\n",
			    filename);
			exit(EXIT_FAILURE);
		}
		if (strcmp(name, CPIO_END_MARKER) == 0) {
			free(name);
			break;
		}
		if (*name == '\0')
			fields[CPIO_HDR_MODE] = 0;

		if (ignore != NULL) {
			char **ptr;

			for (ptr = ignore; *ptr != NULL; ptr++) {
				if (CheckPrefix(*ptr, name)) {
					fields[CPIO_HDR_MODE] = 0;
					break;
				}
			}
		}

		if (fields[CPIO_HDR_MODE] != 0 &&
		    !StripPrefix(name, stripcount)) {
			(void)fprintf(stderr,
				    "%s: Leading path to strip too "
				    "big (-s %d)\n",
				    filename, stripcount);
			exit(EXIT_FAILURE);
		}

		if (prefix != NULL) {
			char *fullname;

		  	fullname = StrCat(prefix, name);
			free(name);
			name = fullname;
		}

		mode = ConvertMode(fields[CPIO_HDR_MODE]);
		length = fields[CPIO_HDR_FILESIZE];
		switch (fields[CPIO_HDR_MODE] & CP_IFMT) {
		case C_ISDIR: {
			PListEntry	*dir;
			bool		old_dir;

			if (length != 0) {
				(void)fprintf(stderr,
				    "%s: error in cpio file.\n",
				filename);
				exit(EXIT_FAILURE);
			}

			if (!MakeTargetDir(name, dirs)) {
				(void)fprintf(stderr,
				    "%s: can't create parent "
				    "directories for \"%s\".\n",
		                    filename, name);
				exit(EXIT_FAILURE);
			}

			if (!MakeDir(name, mode, &old_dir)) {
				(void)fprintf(stderr,
				    "%s: can't create directory "
				    "\"%s\".\n", filename, name);
				exit(EXIT_FAILURE);
			}

			if (!old_dir) {
				dir = PListInsert(dirs, name);
				dir->pe_DirEmpty = true;
			}
			break;
		}
		case C_ISLNK: {
			char *link_target;

			if ((link_target = GetData(in, length)) == NULL) {
				(void)fprintf(stderr,
				    "%s: error in cpio file.\n",
				filename);
				exit(EXIT_FAILURE);
			}

			if (!MakeTargetDir(name, dirs)) {
				(void)fprintf(stderr,
				    "%s: can't create parent "
				    "directories for \"%s\".\n",
		                    filename, name);
				exit(EXIT_FAILURE);
			}

			if (*link_target == '/') {
				char *ptr;

				(void)memmove(link_target, link_target + 1,
				    strlen(link_target));
				ptr = name;
				if (prefix != NULL)
					ptr += strlen(prefix);

				while ((ptr = strchr(ptr, '/')) != NULL) {
					char *new_link_target;

				    	new_link_target = StrCat("../",
					    link_target);
					free(link_target);
					link_target = new_link_target;
					ptr++;
				}
			}

			if (!MakeSymLink(link_target, name)) {
				(void)fprintf(stderr,
				    "%s: can't create symbolic link "
				    "\"%s\".\n", filename, name);
				exit(EXIT_FAILURE);
			}

	    		PListInsert(files, name)->pe_Link = link_target;
			break;
		}
		case C_ISREG:
			if (!MakeTargetDir(name, dirs)) {
				(void)fprintf(stderr,
				    "%s: can't create parent "
				    "directories for \"%s\".\n",
		                    filename, name);
				exit(EXIT_FAILURE);
			}


			if ((last != NULL) && (last->pe_INode !=
			    fields[CPIO_HDR_INODE])) {
				last = NULL;
			}

			if (!WriteFile(in, name, mode, length,
			    (last != NULL)? last->pe_Name : NULL)) {
				(void)fprintf(stderr,
		                    "%s: can't write file \"%s\".\n",
		                    filename, name);
				exit(EXIT_FAILURE);
			}

			last = PListInsert(files, name);
			last->pe_INode = fields[CPIO_HDR_INODE];
			break;
		default:
			if (length > 0 && !SkipAndAlign(in, length)) {
				(void)fprintf(stderr,
				    "%s: error in cpio file.\n",
				    filename);
				exit(EXIT_FAILURE);
			}
					
		}

		free(name);
	}

	FileHandleClose(in);
}

int
main(int argc, char **argv)
{
	char		*progname;
	FILE		*plist_file;
	char		**ignore, *prefix;
	int		opt, stripcount, i;
	PListEntry	*files, *dirs;

	progname = strrchr(argv[0], '/');
	if (progname == NULL)
		progname = argv[0];
	else
		progname++;

	plist_file = NULL;
	ignore = NULL;
	prefix = NULL;
	stripcount = 0;
	while ((opt = getopt(argc, argv, "d:f:i:p:s:")) != -1) {
		switch (opt) {
		case 'd':
			if (chdir(optarg)) {
				perror(optarg);
				return EXIT_FAILURE;
			}
			break;

		case 'f':
			if (plist_file != NULL)
				(void)fclose(plist_file);
			if ((plist_file = fopen(optarg, "a")) == NULL) {
				perror(optarg);
				return EXIT_FAILURE;
			}
			break;

		case 'i':
			ignore = ArrayAdd(ignore, optarg);
			break;

		case 'p':
			if (strlen(optarg) > 0)
				prefix = optarg;
			break;

		case 's':
			stripcount = atoi(optarg);
			if (stripcount <= 0) {
				(void)fprintf(stderr,
				    "%s: -s argument \"%s\" "
				    "must be a positive integer.\n",
				    progname, optarg);
				return EXIT_FAILURE;
			}
			break;

		default:
			Usage(progname);
		}
	}

	if (argc == optind)
		Usage(progname);

	if (prefix != NULL && prefix[strlen(prefix) - 1] != '/')
		prefix = StrCat(prefix, "/");

	files = NULL;
	dirs = NULL;
	for (i = optind; i < argc ; i++)
		ProcessRPM(argv[i], &files, &dirs, ignore, prefix, stripcount);

	if (plist_file != NULL) {
		PListWrite(files, dirs, plist_file);
		(void)fclose(plist_file);
	}

	return EXIT_SUCCESS;
}
