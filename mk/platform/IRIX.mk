# $NetBSD: IRIX.mk,v 1.13 2005/05/03 18:30:12 jlam Exp $
#
# Variable definitions for the IRIX operating system.

ECHO_N?=	${ECHO} -n
IMAKEOPTS+=	-DMakeCmd=${PREFIX}/bin/bmake -DProjectRoot=${X11BASE}
IMAKEOPTS+=	-DManUsr=${PREFIX}
PKGLOCALEDIR?=	share
PS?=		/sbin/ps
RSH?=		/usr/bsd/rsh
SU?=		/sbin/su
TYPE?=		/sbin/type

.if empty(_USE_NEW_TOOLS:M[yY][eE][sS])
AWK?=		/usr/bin/nawk
BASENAME?=	/sbin/basename
CAT?=		/sbin/cat
CHMOD?=		/sbin/chmod
CHOWN?=		/sbin/chown
CHGRP?=		/sbin/chgrp
CMP?=		/usr/bin/cmp
CP?=		/sbin/cp
CUT?=		/usr/bin/cut
DATE?=		/sbin/date
DIRNAME?=	/usr/bin/dirname
ECHO?=		echo			# Shell builtin
EGREP?=		/usr/bin/egrep
EXPR?=		/bin/expr
FALSE?=		false			# Shell builtin
FGREP?=		/usr/bin/fgrep
FILE_CMD?=	/usr/bin/file
FIND?=		/sbin/find
.if exists(${LOCALBASE}/bin/gmake)
GMAKE?=		${LOCALBASE}/bin/gmake
.endif
GREP?=		/sbin/grep
.if exists(${LOCALBASE}/bin/tar)
GTAR?=		${LOCALBASE}/bin/tar
.else
GTAR?=		/sbin/tar
.endif
GUNZIP_CMD?=	/usr/sbin/gunzip -f
.if exists(/usr/sbin/gzcat)
GZCAT?=		/usr/sbin/gzcat
.else
GZCAT?=		/usr/bsd/zcat
.endif
GZIP_CMD?=	/usr/sbin/gzip -nf ${GZIP}
HEAD?=		/usr/bsd/head
HOSTNAME_CMD?=	/usr/bsd/hostname
ID?=		/usr/bin/id
IMAKE?=		/usr/bin/X11/imake ${IMAKEOPTS}
LDCONFIG?=	/usr/bin/true
LN?=		/sbin/ln
LS?=		/sbin/ls
M4?=		/sbin/m4
MAIL_CMD?=	/usr/sbin/mailx
MKDIR?=		/sbin/mkdir -p
MTREE?=		${LOCALBASE}/sbin/mtree
MV?=		/sbin/mv
NICE?=		/sbin/nice
.if exists(${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}patch)
PATCH?=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}patch
_OPSYS_GPATCH_REQD=	YES
.else
PATCHV!=	/usr/sbin/patch -v 2>&1 | ${CUT} -d" " -f3
.  if ${PATCHV} == "2.1"
_OPSYS_GPATCH_REQD=	YES
PATCH=		${LOCALBASE}/bin/${GNU_PROGRAM_PREFIX}patch
.  else
PATCH?=		/usr/sbin/patch -b
.  endif # PATCHV
.endif
PAX?=		${LOCALBASE}/bin/pax
PERL5?=		${LOCALBASE}/bin/perl
PWD_CMD?=	/sbin/pwd		# needs to print physical path
RM?=		/sbin/rm
RMDIR?=		/usr/bin/rmdir
SED?=		/sbin/sed
SETENV?=	/sbin/env
SH?=		/bin/ksh
SHLOCK=		${LOCALBASE}/bin/shlock
SORT?=		/usr/bin/sort
TAIL?=		/usr/bin/tail
TAR?=		${LOCALBASE}/bin/tar
TEE?=		/usr/bin/tee
TEST?=		test			# Shell builtin
TOUCH?=		/usr/bin/touch
TR?=		/usr/bin/tr
TRUE?=		true			# Shell builtin
TSORT?=		/usr/bin/tsort
WC?=		/sbin/wc
XARGS?=		/sbin/xargs
.endif

CPP_PRECOMP_FLAGS?=	# unset
DEF_UMASK?=		022
DEFAULT_SERIAL_DEVICE?=	/dev/null
EXPORT_SYMBOLS_LDFLAGS?=	# Don't add symbols to the dynamic symbol table
MOTIF_TYPE_DEFAULT?=	dt		# default 2.0 compatible libs type
NOLOGIN?=		${FALSE}
ROOT_CMD?=		${SU} - root -c
ROOT_GROUP?=		sys
ROOT_USER?=		root
SERIAL_DEVICES?=	/dev/null
ULIMIT_CMD_datasize?=	ulimit -d `ulimit -H -d`
ULIMIT_CMD_stacksize?=	ulimit -s `ulimit -H -s`
ULIMIT_CMD_memorysize?=	ulimit -v `ulimit -H -v`

# imake installs manpages in weird places
IMAKE_MAN_SOURCE_PATH=	catman/u_man/cat
IMAKE_MAN_SUFFIX=	1
IMAKE_LIBMAN_SUFFIX=	3
IMAKE_FILEMAN_SUFFIX=	5
IMAKE_MAN_DIR=		${IMAKE_MAN_SOURCE_PATH}1/X11
IMAKE_LIBMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}3/X11
IMAKE_FILEMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}5/X11
IMAKE_MANNEWSUFFIX=	z

_DO_SHLIB_CHECKS=	yes		# fixup PLIST for shared libs
_IMAKE_MAKE=		${MAKE}		# program which gets invoked by imake
.if exists(/usr/include/netinet6)
_OPSYS_HAS_INET6=	yes		# IPv6 is standard
.else
_OPSYS_HAS_INET6=	no		# IPv6 is not standard
.endif
_OPSYS_HAS_JAVA=	no		# Java is not standard
_OPSYS_HAS_MANZ=	no		# no MANZ for gzipping of man pages
_OPSYS_HAS_OSSAUDIO=	no		# libossaudio is available
_OPSYS_NEEDS_XPKGWEDGE=	yes		# xpkgwedge is required for X11
_OPSYS_PERL_REQD=			# no base version of perl required
_OPSYS_PTHREAD_AUTO=	no		# -lpthread needed for pthreads
_OPSYS_SHLIB_TYPE=	ELF		# shared lib type
.if defined(_OPSYS_GPATCH_REQD) && ${_OPSYS_GPATCH_REQD} == "YES"
_PATCH_CAN_BACKUP=	yes		# patch(1) can make backups
_PATCH_BACKUP_ARG?=	-b -V simple -z # switch to patch(1) for backup suffix
.else
_PATCH_CAN_BACKUP=	no		# native patch(1) can make backups
.endif
_PREFORMATTED_MAN_DIR=	man		# directory where catman pages are
_USE_GNU_GETTEXT=	no		# Don't use GNU gettext
_USE_RPATH=		yes		# add rpath to LDFLAGS

# flags passed to the linker to extract all symbols from static archives.
# XXX:
# These flags are for the IRIX linker.  If GNU ld is used, these would need
# to be set to --{no-}whole-archive.  So, ugh, let's say we only do
# IRIX tools for the time being.
_OPSYS_WHOLE_ARCHIVE_FLAG=	-Wl,-all
_OPSYS_NO_WHOLE_ARCHIVE_FLAG=	-Wl,-none

# IRIX has /usr/include/iconv.h, but it's not GNU iconv, so mark it
# incompatible.
_INCOMPAT_ICONV=	IRIX-*-*

_STRIPFLAG_CC?=		${_INSTALL_UNSTRIPPED:D:U-s}	# cc(1) option to strip
_STRIPFLAG_INSTALL?=	${_INSTALL_UNSTRIPPED:D:U-s}	# install(1) option to strip

LOCALBASE?=		${DESTDIR}/usr/pkg
PKG_TOOLS_BIN?=		${LOCALBASE}/sbin

CONFIGURE_ENV+=		ABI=${ABI}
MAKE_ENV+=		ABI=${ABI}

LIBABISUFFIX?=		${ABI}

# check for maximum command line length and set it in configure's environment,
# to avoid a test required by the libtool script that takes forever.
_OPSYS_MAX_CMDLEN_CMD=	/usr/sbin/sysconf ARG_MAX

# If games are to be installed setgid, then SETGIDGAME is set to 'yes'
# (it defaults to 'no' as per bsd.pkg.defaults.mk).
# Set the group and mode to meaningful values in that case (defaults to
# BINOWN, BINGRP and BINMODE as per bsd.pkg.defaults.mk).
# FIXME: Adjust to work on this system and enable the lines below.
#.if !(empty(SETGIDGAME:M[yY][eE][sS]))
#GAMEOWN=		games
#GAMEGRP=		games
#GAMEMODE=		2555
#.endif
