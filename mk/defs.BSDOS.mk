# $NetBSD: defs.BSDOS.mk,v 1.8 2004/04/19 20:19:46 jmmv Exp $
#
# Variable definitions for the BSD/OS operating system.

AWK?=		/usr/bin/awk
BASENAME?=	/usr/bin/basename
CAT?=		/bin/cat
CHMOD?=		/bin/chmod
CHOWN?=		/usr/sbin/chown
CHGRP?=		/usr/bin/chgrp
CMP?=		/usr/bin/cmp
CP?=		/bin/cp
#CPP=		/usr/bin/cpp
# BSD/OS doesn't have c++ command
.if !exists(${CXX})
CXX=		/usr/bin/g++
.endif
CUT?=		/usr/bin/cut
DATE?=		/bin/date
DC?=		/usr/bin/dc
DIRNAME?=	/usr/bin/dirname
ECHO?=		echo				# Shell builtin
ECHO_N?=	${ECHO} -n
EGREP?=		/bin/egrep
EXPR?=		/bin/expr
FALSE?=		false				# Shell builtin
FGREP?=		/bin/fgrep
FILE_CMD?=	/usr/bin/file
FIND?=		/usr/bin/find
.if exists(${LOCALBASE}/bin/gmake)
GMAKE?=		${LOCALBASE}/bin/gmake
.else
GMAKE?=		/usr/contrib/bin/gmake
.endif
GREP?=		/bin/grep
.if exists(${LOCALBASE}/bin/gtar)
GTAR?=		${LOCALBASE}/bin/gtar
.else
GTAR?=		/bin/tar
.endif
GUNZIP_CMD?=	/usr/contrib/bin/gunzip -f
GZCAT?=		/usr/contrib/bin/gzcat
GZIP?=		-9
GZIP_CMD?=	/usr/contrib/bin/gzip -nf ${GZIP}
HEAD?=		/usr/bin/head
HOSTNAME_CMD?=	/bin/hostname
ID?=		/usr/bin/id
LDCONFIG?=	/sbin/ldconfig
LN?=		/bin/ln
LS?=		/bin/ls
M4?=		/usr/bin/m4
MAIL_CMD?=	/usr/bin/mail
MKDIR?=		/bin/mkdir -p
.if exists(${LOCALBASE}/sbin/mtree)
MTREE?=	${LOCALBASE}/sbin/mtree
.else
MTREE?=		/usr/sbin/mtree
.endif
MV?=		/bin/mv
NICE?=		/usr/bin/nice
PATCH?=		/usr/contrib/bin/patch
# native /bin/pax doesn't support -O
PAX?=		${LOCALBASE}/bin/pax
PERL5?=		${LOCALBASE}/bin/perl
PKGLOCALEDIR?=	share
PS?=		/bin/ps
PWD_CMD?=	/bin/pwd	# needs to print physical path
RM?=		/bin/rm
RMDIR?=		/bin/rmdir
SED?=		/usr/bin/sed
SETENV?=	/usr/bin/env
# native sh and ksh both have problems under BSD/OS 4.3.1
# /usr/contrib/bin/bash is a symlink to /bin/bash
SH?=		/bin/bash
SHLOCK=		${LOCALBASE}/bin/shlock
SORT?=		/usr/bin/sort
SU?=		/usr/bin/su
TAIL?=		/usr/bin/tail
.if exists(/bin/tar)
TAR?=		/bin/tar
.else
TAR?=		/usr/bin/tar
.endif
TEE?=		/usr/bin/tee
TEST?=		test				# Shell builtin
TOUCH?=		/usr/bin/touch
TR?=		/usr/bin/tr
TRUE?=		true				# Shell builtin
TSORT?=		/usr/bin/tsort
# sh doesn't have built-in type
TYPE?=		which
WC?=		/usr/bin/wc
XARGS?=		/usr/bin/xargs

USERADD?=	/usr/sbin/adduser
GROUPADD?=	/usr/sbin/addgroup

CPP_PRECOMP_FLAGS?=	# unset
DEF_UMASK?=		0022
.if ${OBJECT_FMT} == "ELF"
EXPORT_SYMBOLS_LDFLAGS?=-Wl,-E	# add symbols to the dynamic symbol table
.else
EXPORT_SYMBOLS_LDFLAGS?=-Wl,--export-dynamic
.endif
MOTIF_TYPE_DEFAULT?=	openmotif	# default 2.0 compatible libs type
MOTIF12_TYPE_DEFAULT?=	lesstif12	# default 1.2 compatible libs type
NOLOGIN?=		/sbin/nologin
PKG_TOOLS_BIN?=		${LOCALBASE}/sbin
ROOT_CMD?=		${SU} - root -c
ROOT_USER?=		root
ROOT_GROUP?=	wheel
ULIMIT_CMD_datasize?=	ulimit -d `ulimit -H -d`
ULIMIT_CMD_stacksize?=	ulimit -s `ulimit -H -s`
ULIMIT_CMD_memorysize?=	ulimit -m `ulimit -H -m`

# imake installs manpages in weird places
# XXX: assume NetBSD defaults until somebody determines correct values
IMAKE_MAN_SOURCE_PATH=	man/cat
IMAKE_MAN_SUFFIX=	1
IMAKE_LIBMAN_SUFFIX=	3
IMAKE_FILEMAN_SUFFIX=	5
IMAKE_MAN_DIR=		${IMAKE_MAN_SOURCE_PATH}1
IMAKE_LIBMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}3
IMAKE_FILEMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}5
IMAKE_MANNEWSUFFIX=	0

_DO_SHLIB_CHECKS=	yes	# fixup PLIST for shared libs/run ldconfig
_IMAKE_MAKE=		${MAKE}	# program which gets invoked by imake
.if exists(/usr/include/netinet6)
_OPSYS_HAS_INET6=	yes	# IPv6 is standard
.else
_OPSYS_HAS_INET6=	no	# IPv6 is not standard
.endif
# XXX need to check this for Java
_OPSYS_HAS_JAVA=	no	# Java is not standard
_OPSYS_HAS_MANZ=	yes	# MANZ controls gzipping of man pages
# XXX need to check this for libossaudio
_OPSYS_HAS_OSSAUDIO=	yes	# libossaudio is available
_OPSYS_LIBTOOL_REQD=	1.4.20010614nb18 # base version of libtool required
_OPSYS_PERL_REQD=		# no base version of perl required
_OPSYS_PTHREAD_AUTO=	no	# -lpthread needed for pthreads
_OPSYS_RPATH_NAME=	-R	# name of symbol in rpath directive to linker 
_OPSYS_SHLIB_TYPE=	ELF/a.out	# shared lib type
_PATCH_CAN_BACKUP=	yes	# native patch(1) can make backups
_PATCH_BACKUP_ARG?=	-V simple -b -z	# switch to patch(1) for backup suffix
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

DEFAULT_SERIAL_DEVICE?=	/dev/null
SERIAL_DEVICES?=	/dev/null

PKG_CREATE_USERGROUP=	NO # until it works

# check for maximum command line length and set it in configure's environment,
# to avoid a test required by the libtool script that takes forever.
# FIXME: Adjust to work on this system and enable the lines below.
#.if defined(GNU_CONFIGURE) && defined(USE_LIBTOOL)
#_OPSYS_MAX_CMDLEN!=	/sbin/sysctl -n kern.argmax
#CONFIGURE_ENV+=		lt_cv_sys_max_cmd_len=${_OPSYS_MAX_CMDLEN}
#.endif
