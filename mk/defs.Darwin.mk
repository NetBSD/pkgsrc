# $NetBSD: defs.Darwin.mk,v 1.71 2004/04/19 20:19:46 jmmv Exp $
#
# Variable definitions for the Darwin operating system.

AWK?=		/usr/bin/awk
BASENAME?=	/usr/bin/basename
CAT?=		/bin/cat
CHMOD?=		/bin/chmod
CHOWN?=		/usr/sbin/chown
CHGRP?=		/usr/bin/chgrp
CMP?=		/usr/bin/cmp
CP?=		/bin/cp
CUT?=		/usr/bin/cut
DATE?=		/bin/date
DC?=		/usr/bin/dc
DIRNAME?=	/usr/bin/dirname
ECHO?=		echo				# Shell builtin
ECHO_N?=	${ECHO} -n
EGREP?=		/usr/bin/egrep
EXPR?=		/bin/expr
FALSE?=		false				# Shell builtin
FILE_CMD?=	/usr/bin/file
FIND?=		/usr/bin/find
FGREP?=		/usr/bin/fgrep
GMAKE?=		/usr/bin/gnumake
GREP?=		/usr/bin/grep
GTAR?=		/usr/bin/gnutar	
GUNZIP_CMD?=	/usr/bin/gunzip -f
GZCAT?=		/usr/bin/gzcat
GZIP?=		-9
GZIP_CMD?=	/usr/bin/gzip -nf ${GZIP}
HEAD?=		/usr/bin/head
HOSTNAME_CMD?=	/bin/hostname
ID?=		/usr/bin/id
IMAKE?=		${X11BASE}/bin/imake ${IMAKEOPTS}
IMAKEOPTS+=	-DBuildHtmlManPages=NO
LDCONFIG?=	/sbin/ldconfig
LDD?=		/usr/bin/otool -L
LN?=		/bin/ln
LS?=		/bin/ls
M4?=		/usr/bin/m4 
MAIL_CMD?=	/usr/bin/mail
MKDIR?=		/bin/mkdir -p
MTREE?=		/usr/sbin/mtree
MV?=		/bin/mv
NICE?=		/usr/bin/nice
PATCH?=		/usr/bin/patch
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
SED?=		/usr/bin/sed
SETENV?=	/usr/bin/env
SH?=		/bin/sh
SHLOCK=		/usr/bin/shlock
SORT?=		/usr/bin/sort
SU?=		/usr/bin/su
TAIL?=		/usr/bin/tail
.if exists(${LOCALBASE}/bin/tar)
TAR?=		${LOCALBASE}/bin/tar
.else
TAR?=		/usr/bin/tar
.endif
TEE?=		/usr/bin/tee
TEST?=		test				# Shell builtin
TOUCH?=		/usr/bin/touch
TR?=		/usr/bin/tr
TRUE?=		true				# Shell builtin
TSORT?=		/usr/bin/tsort
TYPE?=		type				# Shell builtin
WC?=		/usr/bin/wc
XARGS?=		/usr/bin/xargs

CPP_PRECOMP_FLAGS?=	-no-cpp-precomp	# use the GNU cpp, not the OS X cpp
DEF_UMASK?=		0022
DEFAULT_SERIAL_DEVICE?=	/dev/null
EXPORT_SYMBOLS_LDFLAGS?=	# Don't add symbols to the dynamic symbol table
MOTIF_TYPE_DEFAULT?=	openmotif	# default 2.0 compatible libs type
MOTIF12_TYPE_DEFAULT?=	lesstif12	# default 1.2 compatible libs type
NOLOGIN?=		${FALSE}
PKG_TOOLS_BIN?=		${LOCALBASE}/sbin
ROOT_CMD?=		sudo sh -c
ROOT_GROUP?=		wheel
ROOT_USER?=		root
SERIAL_DEVICES?=	/dev/null
ULIMIT_CMD_datasize?=	ulimit -d `ulimit -H -d`
ULIMIT_CMD_stacksize?=	ulimit -s `ulimit -H -s`
ULIMIT_CMD_memorysize?=	ulimit -m `ulimit -H -m`

GROUPADD?=		${LOCALBASE}/sbin/groupadd
USERADD?=		${LOCALBASE}/sbin/useradd
_PKG_USER_HOME?=	/var/empty	# to match other system accounts
_PKG_USER_SHELL?=	/usr/bin/false	# to match other system accounts
.if defined(USE_USERADD) || defined(USE_GROUPADD)
DEPENDS+=	user>=20040331:../../sysutils/user_darwin
.endif

# imake installs manpages in weird places
# these values from /usr/X11R6/lib/X11/config/Imake.tmpl
IMAKE_MAN_SOURCE_PATH=	man/man
IMAKE_MAN_SUFFIX=	1
IMAKE_LIBMAN_SUFFIX=	3
IMAKE_FILEMAN_SUFFIX=	5
IMAKE_MAN_DIR=		${IMAKE_MAN_SOURCE_PATH}1
IMAKE_LIBMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}3
IMAKE_FILEMAN_DIR=	${IMAKE_MAN_SOURCE_PATH}5
IMAKE_MANNEWSUFFIX=	${IMAKE_MAN_SUFFIX}

_DO_SHLIB_CHECKS=	yes	# on installation, fixup PLIST for shared libs
_IMAKE_MAKE=		${MAKE}	# program which gets invoked by imake
.if ${OS_VERSION:R} >= 6
_OPSYS_HAS_INET6=	yes	# IPv6 is standard
.else
_OPSYS_HAS_INET6=	no	# IPv6 is not standard
.endif
_OPSYS_HAS_JAVA=	yes	# Java is standard
_OPSYS_HAS_MANZ=	yes	# MANZ controls gzipping of man pages
_OPSYS_HAS_OSSAUDIO=	no	# libossaudio is available
_OPSYS_LIBTOOL_REQD=	1.5.2nb5 # base version of libtool required
_OPSYS_PERL_REQD=	5.8.0	# base version of perl required
_OPSYS_PTHREAD_AUTO=	yes	# -lpthread not needed for pthreads
_OPSYS_RPATH_NAME=	-L	# darwin has no rpath, use -L instead
_OPSYS_SHLIB_TYPE=	dylib	# shared lib type
_PATCH_CAN_BACKUP=	yes	# native patch(1) can make backups
_PATCH_BACKUP_ARG?=	-V simple -b -z	# switch to patch(1) for backup suffix
_PREFORMATTED_MAN_DIR=	cat	# directory where catman pages are
_USE_GNU_GETTEXT=	no	# Don't use GNU gettext
_USE_RPATH=		no	# don't add rpath to LDFLAGS

# flags passed to the linker to extract all symbols from static archives.
# this is GNU ld.
_OPSYS_WHOLE_ARCHIVE_FLAG=	-Wl,--whole-archive
_OPSYS_NO_WHOLE_ARCHIVE_FLAG=	-Wl,--no-whole-archive

.if !defined(DEBUG_FLAGS)
_STRIPFLAG_CC?=		-Wl,-x	# cc(1) option to strip
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
