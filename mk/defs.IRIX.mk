# $NetBSD: defs.IRIX.mk,v 1.7 2002/12/03 20:53:41 agc Exp $
#
# Variable definitions for the IRIX operating system.

AWK?=		/usr/bin/awk
BASENAME?=	/sbin/basename
CAT?=		/sbin/cat
CHMOD?=		/sbin/chmod
CHOWN?=		/sbin/chown
CHGRP?=		/sbin/chgrp
CMP?=		/usr/bin/cmp
CP?=		/sbin/cp
CUT?=		/usr/bin/cut
DC?=		/usr/bin/dc
DIRNAME?=	/usr/bin/dirname
ECHO?=		/sbin/echo
EGREP?=		/bin/grep
EXPR?=		/bin/expr
FALSE?=		/usr/bin/false
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
.if exists(${ZOULARISBASE}/bin/gzip)
GUNZIP_CMD?=	${ZOULARISBASE}/bin/gunzip -f
GZCAT?=		${ZOULARISBASE}/bin/zcat
GZIP?=		-9
GZIP_CMD?=	${ZOULARISBASE}/bin/gzip -nf ${GZIP}
.elif exists(${LOCALBASE}/bin/gzip)
GUNZIP_CMD?=	${LOCALBASE}/bin/gunzip -f
GZCAT?=		${LOCALBASE}/bin/zcat
GZIP?=		-9
GZIP_CMD?=	${LOCALBASE}/bin/gzip -nf ${GZIP}
.endif
LDCONFIG?=	/usr/bin/true
HEAD?=		/usr/bsd/head
ID?=		/usr/bin/id
LN?=		/sbin/ln
LS?=		/sbin/ls
MKDIR?=		/sbin/mkdir -p
.if exists(${LOCALBASE}/sbin/mtree)
MTREE?=		${LOCALBASE}/sbin/mtree
.endif
MTREE?=		${ZOULARISBASE}/bin/mtree
MV?=		/sbin/mv
PATCH?=		/usr/sbin/patch -b
PAX?=		/usr/sbin/pax
PERL5?=		/usr/sbin/perl
PKGLOCALEDIR?=	share
PS?=		/sbin/ps
RM?=		/sbin/rm
RMDIR?=		/usr/bin/rmdir
SED?=		/sbin/sed
SETENV?=	/sbin/env
SH?=		/bin/sh
SHLOCK=		${LOCALBASE}/bin/shlock
SORT?=		/usr/bin/sort
SU?=		/sbin/su
TAIL?=		/usr/bin/tail
TEST?=		/sbin/test
TOUCH?=		/usr/bin/touch
TR?=		/usr/bin/tr
TRUE?=		/usr/bin/true
TYPE?=		/sbin/type
WC?=		/usr/bin/wc
XARGS?=		/sbin/xargs

CPP_PRECOMP_FLAGS?=	# unset
DEF_UMASK?=		022
DEFAULT_SERIAL_DEVICE?=	/dev/null
EXPORT_SYMBOLS_LDFLAGS?=	# Don't add symbols to the dynamic symbol table
GROUPADD?=		${FALSE}
MOTIF_TYPE_DEFAULT?=	dt		# default 2.0 compatible libs type
MOTIF12_TYPE_DEFAULT?=	dt		# default 1.2 compatible libs type
NOLOGIN?=		${FALSE}
ROOT_CMD?=		${SU} - root -c
ROOT_GROUP?=		sys
ROOT_USER?=		root
SERIAL_DEVICES?=	/dev/null
ULIMIT_CMD_datasize?=	ulimit -d `ulimit -H -d`
ULIMIT_CMD_stacksize?=	ulimit -s `ulimit -H -s`
ULIMIT_CMD_memorysize?=	ulimit -v `ulimit -H -v`
USERADD?=		${FALSE}

_DO_SHLIB_CHECKS=	yes		# fixup PLIST for shared libs
_IMAKE_MAKE=		${MAKE}		# program which gets invoked by imake
_OPSYS_HAS_GMAKE=	no		# GNU make is not standard
_OPSYS_HAS_JAVA=	no		# Java is not standard
_OPSYS_HAS_MANZ=	no		# no MANZ for gzipping of man pages
_OPSYS_HAS_OSSAUDIO=	no		# libossaudio is available
_OPSYS_LIBTOOL_REQD=	1.4.20010614nb9 # base version of libtool required
_OPSYS_RPATH_NAME=	-rpath,		# name of symbol in rpath directive to linker 
_PATCH_CAN_BACKUP=	no		# native patch(1) can make backups
_PREFORMATTED_MAN_DIR=	man		# directory where catman pages are
_USE_GNU_GETTEXT=	no		# Don't use GNU gettext
_USE_RPATH=		yes		# add rpath to LDFLAGS

.if !defined(DEBUG_FLAGS)
_STRIPFLAG_CC?=		-s	# cc(1) option to strip
_STRIPFLAG_INSTALL?=	-s	# install(1) option to strip
.endif

LOCALBASE?=             ${DESTDIR}/usr/pkg
.if !defined(ZOULARISBASE)
.  if exists(${LOCALBASE}/bsd)
ZOULARISBASE:=		${LOCALBASE}/bsd
.  else
ZOULARISBASE:=		${LOCALBASE}
.  endif
.endif
.if exists(${LOCALBASE}/sbin/pkg_info)
PKG_TOOLS_BIN?=		${LOCALBASE}/sbin
.endif
PKG_TOOLS_BIN?=		${ZOULARISBASE}/bin
