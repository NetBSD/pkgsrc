# $NetBSD: defs.Linux.mk,v 1.28 2002/07/15 16:24:01 schmonz Exp $
#
# Variable definitions for the Linux operating system.

AWK?=		/usr/bin/awk
BASENAME?=	/bin/basename
CAT?=		/bin/cat
CHMOD?=		/bin/chmod
CHOWN?=		/bin/chown
CHGRP?=		/bin/chgrp
CMP?=		cmp
CP?=		/bin/cp
CUT?=		/bin/cut
DC?=		/usr/bin/dc
DIRNAME?=	/usr/bin/dirname
ECHO?=		/bin/echo
EGREP?=		/bin/egrep
FALSE?=		/bin/false
FILE_CMD?=	/usr/bin/file
FIND?=		/usr/bin/find
GMAKE?=		/usr/bin/make
GREP?=		/bin/grep
GTAR?=		/bin/tar
GUNZIP_CMD?=	/usr/bin/gunzip -f
GZCAT?=		/bin/zcat
GZIP?=		-9
GZIP_CMD?=	/usr/bin/gzip -nf ${GZIP}
HEAD?=		/usr/bin/head
ID?=		/usr/bin/id
LDCONFIG?=	/sbin/ldconfig
LN?=		/bin/ln
LS?=		/bin/ls
MKDIR?=		/bin/mkdir -p
MTREE?=		${ZOULARISBASE}/sbin/mtree
MV?=		/bin/mv
PATCH?=		/usr/bin/patch
PAX?=		${ZOULARISBASE}/bin/pax
PERL5?=		${LOCALBASE}/bin/perl
PKGLOCALEDIR?=	share
PS?=		/bin/ps
RM?=		/bin/rm
RMDIR?=		/bin/rmdir
SED?=		/bin/sed
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
TEST?=		/usr/bin/test
TOUCH?=		/bin/touch
TR?=		/usr/bin/tr
TRUE?=		/bin/true
TYPE?=		type
WC?=		/usr/bin/wc
XARGS?=		/usr/bin/xargs -r

CPP_PRECOMP_FLAGS?=	# unset
DEF_UMASK?=		022
DEFAULT_SERIAL_DEVICE?=	/dev/null
GROUPADD?=		/usr/sbin/groupadd
MOTIF_TYPE_DEFAULT?=	openmotif	# default 2.0 compatible libs type
MOTIF12_TYPE_DEFAULT?=	lesstif12	# default 1.2 compatible libs type
NOLOGIN?=		${FALSE}
PKG_TOOLS_BIN?=		${ZOULARISBASE}/sbin
ROOT_CMD?=		${SU} - root -c
ROOT_GROUP?=		wheel
ROOT_USER?=		root
SERIAL_DEVICES?=	/dev/null
USERADD?=		/usr/sbin/useradd
ZOULARISBASE?=		/usr/pkg

_DO_LIBINTL_CHECKS=	no	# perform checks for valid libintl
_DO_SHLIB_CHECKS=	no	# on installation, fixup PLIST for shared libs
_IMAKE_MAKE=		${MAKE}	# program which gets invoked by imake
_OPSYS_HAS_GMAKE=	yes	# GNU make is standard
_OPSYS_HAS_MANZ=	no	# no MANZ for gzipping of man pages
_OPSYS_HAS_OSSAUDIO=	no	# libossaudio is available
_PATCH_BACKUP_ARG= 	-b -V simple -z	# switch to patch(1) for backup suffix
_PREFORMATTED_MAN_DIR=	cat	# directory where catman pages are
_USE_RPATH=		yes	# add rpath to LDFLAGS

.if !defined(DEBUG_FLAGS)
_STRIPFLAG_CC?=		-s	# cc(1) option to strip
_STRIPFLAG_INSTALL?=	-s	# install(1) option to strip
.endif
