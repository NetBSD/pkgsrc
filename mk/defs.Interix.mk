# $NetBSD: defs.Interix.mk,v 1.15 2004/04/22 04:14:27 tv Exp $
#
# Variable definitions for the Interix operating system.

AWK?=		/usr/contrib/bin/gawk
BASENAME?=	/bin/basename
CAT?=		/bin/cat
CHMOD?=		/bin/chmod
CHOWN?=		/bin/chown
CHGRP?=		/bin/chgrp
CMP?=		/bin/cmp
CP?=		/bin/cp
CUT?=		/bin/cut
DATE?=		/bin/date
DC?=		/bin/dc
DIRNAME?=	/bin/dirname
ECHO?=		echo				# Shell builtin
ECHO_N?=	/bin/printf %s			# does not support "echo -n"
EGREP?=		/bin/egrep
EXPR?=		/bin/expr
FALSE?=		false				# Shell builtin
FGREP?=		/bin/fgrep
FILE_CMD?=	/bin/file
FIND?=		/bin/find
GMAKE?=		${LOCALBASE}/bin/gmake
GREP?=		/bin/grep
.if exists(${LOCALBASE}/bin/gtar)
GTAR?=		${LOCALBASE}/bin/gtar
.else
GTAR?=		${LOCALBASE}/bin/tar
.endif
GUNZIP_CMD?=	/usr/contrib/bin/gunzip -f
GZCAT?=		/usr/contrib/bin/gunzip -c
GZIP?=		-9
GZIP_CMD?=	/usr/contrib/bin/gzip -nf ${GZIP}
HEAD?=		/bin/head
HOSTNAME_CMD?=	/bin/hostname
ID?=		/bin/id
IMAKE?=		${X11BASE}/bin/imake ${IMAKEOPTS}
IMAKEOPTS+=	-DBuildHtmlManPages=NO
LDCONFIG?=	/bin/true
LN?=		/bin/ln
LS?=		/bin/ls
M4?=		/bin/m4
MAIL_CMD?=	/bin/mail
MKDIR?=		/bin/mkdir -p
MTREE?=		${LOCALBASE}/sbin/mtree
MV?=		/bin/mv
NICE?=		/bin/nice
PATCH?=		${LOCALBASE}/bin/gpatch
.if exists(${LOCALBASE}/bin/pax)
PAX?=		${LOCALBASE}/bin/pax
.else
PAX?=		/bin/pax
.endif
PERL5?=		${LOCALBASE}/bin/perl
PKGLOCALEDIR?=	share
PS?=		/bin/ps
PWD_CMD?=	/bin/pwd	# needs to print physical path
RM?=		/bin/rm
RMDIR?=		/bin/rmdir
SED?=		${LOCALBASE}/bin/nbsed
SETENV?=	/bin/env
SH?=		/bin/sh
SHLOCK=		${LOCALBASE}/bin/shlock
SORT?=		/bin/sort
SU?=		/bin/su
TAIL?=		/bin/tail
TAR?=		${LOCALBASE}/bin/tar
TEE?=		/bin/tee
TEST?=		test				# Shell builtin
TOUCH?=		/bin/touch
TR?=		/bin/tr
TRUE?=		true				# Shell builtin
TSORT?=		/bin/tsort
TYPE?=		type				# Shell builtin
WC?=		/bin/wc
XARGS?=		/bin/xargs

# XXXTV
USERADD?=	${FALSE}
GROUPADD?=	${FALSE}

CPP_PRECOMP_FLAGS?=	# unset
DEF_UMASK?=		002
EXPORT_SYMBOLS_LDFLAGS?=-Wl,-E	# add symbols to the dynamic symbol table

MOTIF_TYPE_DEFAULT?=	openmotif	# default 2.0 compatible libs type
MOTIF12_TYPE_DEFAULT?=	lesstif12	# default 1.2 compatible libs type
NOLOGIN?=		/sbin/nologin
PKG_TOOLS_BIN?=		${LOCALBASE}/sbin
PKGDIRMODE?=		775
ROOT_CMD?=		${SU} - ${ROOT_USER} -c
ROOT_USER?=		${BINOWN}
ROOT_GROUP?=		+Administrators
TOUCH_FLAGS?=
ULIMIT_CMD_datasize?=	ulimit -d `ulimit -H -d`
ULIMIT_CMD_stacksize?=	ulimit -s `ulimit -H -s`
ULIMIT_CMD_memorysize?=	ulimit -m `ulimit -H -m`

# imake installs manpages in weird places
IMAKE_MAN_SOURCE_PATH=	man/man
IMAKE_MAN_SUFFIX=	n
IMAKE_LIBMAN_SUFFIX=	3
IMAKE_KERNMAN_SUFFIX=	4
IMAKE_FILEMAN_SUFFIX=	5
IMAKE_MISCMAN_SUFFIX=	7
IMAKE_MAN_DIR=		${IMAKE_MAN_SOURCE_PATH}n
IMAKE_LIBMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}3
IMAKE_KERNMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}4
IMAKE_FILEMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}5
IMAKE_MISCMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}7
IMAKE_MANNEWSUFFIX=	${IMAKE_MAN_SUFFIX}

_DO_SHLIB_CHECKS=	yes	# fixup PLIST for shared libs/run ldconfig
_IMAKE_MAKE=		${MAKE}	# program which gets invoked by imake
.if exists(/usr/include/netinet6)
_OPSYS_HAS_INET6=	yes	# IPv6 is standard
.else
_OPSYS_HAS_INET6=	no	# IPv6 is not standard
.endif
_OPSYS_HAS_JAVA=	no	# Java is not standard
_OPSYS_HAS_MANZ=	yes	# MANZ controls gzipping of man pages
_OPSYS_HAS_OSSAUDIO=	no	# libossaudio is available
_OPSYS_LIBTOOL_REQD=	1.5.2nb7 # base version of libtool required
_OPSYS_PERL_REQD=		# no base version of perl required
_OPSYS_PKGTOOLS_REQD=	20040330
_OPSYS_PTHREAD_AUTO=	no	# -lpthread needed for pthreads
_OPSYS_RPATH_NAME=	-R	# name of symbol in rpath directive to linker 
_OPSYS_SHLIB_TYPE=	ELF	# shared lib type - not exactly true, but near enough
_PATCH_CAN_BACKUP=	yes	# native patch(1) can make backups
_PATCH_BACKUP_ARG?=	-b -V simple -z	# switch to patch(1) for backup suffix
_PREFORMATTED_MAN_DIR=	cat	# directory where catman pages are
_USE_GNU_GETTEXT=	yes	# gettext not in base system
_USE_RPATH=		yes	# add rpath to LDFLAGS

# flags passed to the linker to extract all symbols from static archives.
# this is GNU ld.
_OPSYS_WHOLE_ARCHIVE_FLAG=	-Wl,--whole-archive
_OPSYS_NO_WHOLE_ARCHIVE_FLAG=	-Wl,--no-whole-archive

.if !defined(DEBUG_FLAGS)
_STRIPFLAG_CC?=		-s	# cc(1) option to strip
_STRIPFLAG_INSTALL?=	-s	# install(1) option to strip
.endif

DEFAULT_SERIAL_DEVICE?=	/dev/tty00
SERIAL_DEVICES?=	/dev/tty00 /dev/tty01 /dev/tty02 /dev/tty03

# Interix needs -D_ALL_SOURCE everywhere; little compiles without it.
.if ${CPPFLAGS:M-D_ALL_SOURCE} == ""
CPPFLAGS+=		-D_ALL_SOURCE
.endif

# Interix gcc "PIC" is broken, but non-"PIC" is shlib linkable.
# We need to AVOID -fpic/-fPIC options to gcc.
BUILDLINK_TRANSFORM+=	S:-fpic: S:-fPIC:

# check for maximum command line length and set it in configure's environment,
# to avoid a test required by the libtool script that takes forever.
.if defined(GNU_CONFIGURE) && defined(USE_LIBTOOL)
CONFIGURE_ENV+=		lt_cv_sys_max_cmd_len=262144
.endif
