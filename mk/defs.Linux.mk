# $NetBSD: defs.Linux.mk,v 1.69 2004/04/19 20:19:46 jmmv Exp $
#
# Variable definitions for the Linux operating system.

AWK?=		/usr/bin/awk
.if exists(/bin/basename)
BASENAME?=	/bin/basename
.elif exists(/usr/bin/basename)
BASENAME?=	/usr/bin/basename
.endif
CAT?=		/bin/cat
CHMOD?=		/bin/chmod
CHOWN?=		/bin/chown
CHGRP?=		/bin/chgrp
CMP?=		cmp
CP?=		/bin/cp
.if exists(/bin/cut)
CUT?=		/bin/cut
.else
CUT?=		/usr/bin/cut
.endif
DATE?=		/bin/date
DC?=		/usr/bin/dc
DIRNAME?=	/usr/bin/dirname
ECHO?=		/bin/echo
ECHO_N?=	${ECHO} -n
.if exists(/bin/egrep)
EGREP?=		/bin/egrep
.elif exists(/usr/bin/egrep)
EGREP?=		/usr/bin/egrep
.endif
EXPR?=		/usr/bin/expr
FALSE?=		/bin/false
.if exists(/bin/fgrep)
FGREP?=		/bin/fgrep
.elif exists(/usr/bin/fgrep)
FGREP?=		/usr/bin/fgrep
.endif
FILE_CMD?=	/usr/bin/file
FIND?=		/usr/bin/find
.if exists(/usr/bin/make)
GMAKE?=		/usr/bin/make
_TOOLS_OPSYS_HAS_GNU.make+=	${MACHINE_PLATFORM}
.else
GMAKE?=		${LOCALBASE}/bin/gmake
.endif
.if exists(/bin/grep)
GREP?=		/bin/grep
.elif exists(/usr/bin/grep)
GREP?=		/usr/bin/grep
.endif
GTAR?=		/bin/tar
.if exists(/usr/bin/gunzip)
GUNZIP_CMD?=	/usr/bin/gunzip -f
.else
GUNZIP_CMD?=	/bin/gunzip -f
.endif
.if exists(/usr/bin/gzip)
GZIP_CMD?=	/usr/bin/gzip -nf ${GZIP}
.else
GZIP_CMD?=	/bin/gzip -nf ${GZIP}
.endif
GZCAT?=		/bin/zcat
GZIP?=		-9
.if exists(/bin/head)
HEAD?=		/bin/head
.else
HEAD?=		/usr/bin/head
.endif
HOSTNAME_CMD?=	/bin/hostname
ID?=		/usr/bin/id
IMAKE?=		${X11BASE}/bin/imake ${IMAKEOPTS}
IMAKEOPTS+=	-DBuildHtmlManPages=NO
LDCONFIG?=	/sbin/ldconfig
LN?=		/bin/ln
LS?=		/bin/ls
M4?=		/usr/bin/m4
.if exists(/bin/mail)
MAIL_CMD?=	/bin/mail # RH, Mandrake
.else
MAIL_CMD?=	/usr/bin/mail # Debian, Slackware, SuSE
.endif
MKDIR?=		/bin/mkdir -p
MTREE?=		${LOCALBASE}/sbin/mtree
MV?=		/bin/mv
.if exists(/bin/nice)
NICE?=		/bin/nice
.else
NICE?=		/usr/bin/nice
.endif
PATCH?=		/usr/bin/patch
PAX?=		${LOCALBASE}/bin/pax
PERL5?=		${LOCALBASE}/bin/perl
PKGLOCALEDIR?=	share
PS?=		/bin/ps
PWD_CMD?=	/bin/pwd	# needs to print physical path
RM?=		/bin/rm
RMDIR?=		/bin/rmdir
.if exists(/bin/sed)
SED?=		/bin/sed
.elif exists(/usr/bin/sed)
SED?=		/usr/bin/sed
.endif
SETENV?=	/usr/bin/env
SH?=		/bin/sh
SHLOCK=		${LOCALBASE}/bin/shlock
.if exists(/bin/sort)
SORT?=		/bin/sort
.else
SORT?=		/usr/bin/sort
.endif
SU?=		/bin/su
TAIL?=		/usr/bin/tail
TAR?=		${LOCALBASE}/bin/tar
TEE?=		/usr/bin/tee
.if exists(/bin/test)
TEST?=		/bin/test
.else
TEST?=		/usr/bin/test
.endif
.if exists(/bin/touch)
TOUCH?=		/bin/touch
.else
TOUCH?=		/usr/bin/touch
.endif
TR?=		/usr/bin/tr
TRUE?=		/bin/true
TSORT?=		/usr/bin/tsort
TYPE?=		type
WC?=		/usr/bin/wc
XARGS?=		/usr/bin/xargs -r

CPP_PRECOMP_FLAGS?=	# unset
DEF_UMASK?=		022
DEFAULT_SERIAL_DEVICE?=	/dev/null
EXPORT_SYMBOLS_LDFLAGS?=	# Don't add symbols to the dynamic symbol table
GROUPADD?=		/usr/sbin/groupadd
MOTIF_TYPE_DEFAULT?=	openmotif	# default 2.0 compatible libs type
MOTIF12_TYPE_DEFAULT?=	lesstif12	# default 1.2 compatible libs type
NOLOGIN?=		${FALSE}
PKG_TOOLS_BIN?=		${LOCALBASE}/sbin
ROOT_CMD?=		${SU} - root -c
ROOT_GROUP?=		root
ROOT_USER?=		root
SERIAL_DEVICES?=	/dev/null
ULIMIT_CMD_datasize?=	ulimit -d `ulimit -H -d`
ULIMIT_CMD_stacksize?=	ulimit -s `ulimit -H -s`
ULIMIT_CMD_memorysize?=	ulimit -m `ulimit -H -m`
USERADD?=		/usr/sbin/useradd

# imake installs manpages in weird places
# these values from /usr/X11R6/lib/X11/config/linux.cf
IMAKE_MAN_SOURCE_PATH=	man/man
IMAKE_MAN_SUFFIX=	1x
IMAKE_LIBMAN_SUFFIX=	3x
IMAKE_KERNMAN_SUFFIX=	4
IMAKE_FILEMAN_SUFFIX=	5x
IMAKE_MISCMAN_SUFFIX=	7
IMAKE_MAN_DIR=		${IMAKE_MAN_SOURCE_PATH}1
IMAKE_LIBMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}3
IMAKE_KERNMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}4
IMAKE_FILEMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}5
IMAKE_MISCMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}7
IMAKE_MANNEWSUFFIX=	${IMAKE_MAN_SUFFIX}

_DO_SHLIB_CHECKS=	no	# on installation, fixup PLIST for shared libs
_IMAKE_MAKE=		${MAKE}	# program which gets invoked by imake
.if exists(/usr/include/netinet6) || exists(/usr/include/linux/in6.h)
_OPSYS_HAS_INET6=	yes	# IPv6 is standard
.else
_OPSYS_HAS_INET6=	no	# IPv6 is not standard
.endif
_OPSYS_HAS_JAVA=	no	# Java is not standard
_OPSYS_HAS_MANZ=	no	# no MANZ for gzipping of man pages
_OPSYS_HAS_OSSAUDIO=	no	# libossaudio is available
_OPSYS_PERL_REQD=		# no base version of perl required
_OPSYS_PTHREAD_AUTO=	no	# -lpthread needed for pthreads
_OPSYS_RPATH_NAME=	-R	# name of symbol in rpath directive to linker 
_OPSYS_SHLIB_TYPE=	ELF/a.out	# shared lib type
_PATCH_CAN_BACKUP=	yes	# native patch(1) can make backups
_PATCH_BACKUP_ARG?= 	-b -V simple -z	# switch to patch(1) for backup suffix
_PREFORMATTED_MAN_DIR=	cat	# directory where catman pages are
_USE_GNU_GETTEXT=	no	# Don't use GNU gettext
_USE_RPATH=		yes	# add rpath to LDFLAGS

# flags passed to the linker to extract all symbols from static archives.
# this is GNU ld.
_OPSYS_WHOLE_ARCHIVE_FLAG=	-Wl,--whole-archive
_OPSYS_NO_WHOLE_ARCHIVE_FLAG=	-Wl,--no-whole-archive

.if !defined(DEBUG_FLAGS)
_STRIPFLAG_CC?=		-s	# cc(1) option to strip
_STRIPFLAG_INSTALL?=	-s	# install(1) option to strip
.endif

LOCALBASE?=		${DESTDIR}/usr/pkg

# check for maximum command line length and set it in configure's environment,
# to avoid a test required by the libtool script that takes forever.
# FIXME: Adjust to work on this system and enable the lines below.
#.if defined(GNU_CONFIGURE) && defined(USE_LIBTOOL)
#_OPSYS_MAX_CMDLEN!=	/sbin/sysctl -n kern.argmax
#CONFIGURE_ENV+=		lt_cv_sys_max_cmd_len=${_OPSYS_MAX_CMDLEN}
#.endif
