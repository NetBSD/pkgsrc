# $NetBSD: defs.Linux.mk,v 1.19 2001/11/21 13:57:31 agc Exp $
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
MTREE?=		${ZOULARISBASE}/bin/mtree
MV?=		/bin/mv
PATCH?=		/usr/bin/patch
PAX?=		${ZOULARISBASE}/bin/pax
PKGLOCALEDIR?=	share
RM?=		/bin/rm
RMDIR?=		/bin/rmdir
SED?=		/bin/sed
SETENV?=	/usr/bin/env
SH?=		/bin/sh
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

DEF_UMASK?=	022
GROUPADD?=	/usr/sbin/groupadd
MOTIF_TYPE_DEFAULT?=	openmotif	# default 2.0 compatible libs type
MOTIF12_TYPE_DEFAULT?=	lesstif12	# default 1.2 compatible libs type
NOLOGIN?=	${FALSE}
USERADD?=	/usr/sbin/useradd

ROOT_USER?=	root
ROOT_GROUP?=	wheel

_DO_LIBINTL_CHECKS=	no	# perform checks for valid libintl
_DO_SHLIB_CHECKS=	no	# on installation, fixup PLIST for shared libs
_IMAKE_MAKE=		${MAKE}	# program which gets invoked by imake
_OPSYS_HAS_MANZ=	no	# no MANZ for gzipping of man pages
_OPSYS_HAS_OSSAUDIO=	no	# libossaudio is available
_PATCH_BACKUP_ARG= 	-z	# switch to patch(1) for backup file
_PREFORMATTED_MAN_DIR=	cat	# directory where catman pages are
_USE_RPATH=		yes	# add rpath to LDFLAGS
