# $NetBSD: defs.SunOS.mk,v 1.14 2001/11/21 13:44:44 agc Exp $
#
# Variable definitions for the SunOS/Solaris operating system.

AWK?=		/usr/bin/nawk
BASENAME?=	/usr/bin/basename
CAT?=		/usr/bin/cat
CHMOD?=		/usr/bin/chmod
CHOWN?=		/usr/bin/chown
CHGRP?=		/usr/bin/chgrp
CMP?=		cmp
CP?=		/usr/bin/cp
CUT?=		/usr/bin/cut
DC?=		/usr/bin/dc
DIRNAME?=	/usr/bin/dirname
ECHO?=		/usr/ucb/echo
EGREP?=		/usr/xpg4/bin/egrep
FALSE?=		/usr/bin/false
FILE_CMD?=	/usr/bin/file
FIND?=		/usr/bin/find
GREP?=		/usr/bin/grep
GTAR?=		${ZOULARISBASE}/bin/tar
.if exists(/usr/bin/gzip)
GUNZIP_CMD?=	/usr/bin/gunzip -f
GZCAT?=		/usr/bin/gzcat
GZIP?=		-9
GZIP_CMD?=	/usr/bin/gzip -nf ${GZIP}
.else
GUNZIP_CMD?=	${LOCALBASE}/bin/gunzip -f
GZCAT?=		${LOCALBASE}/bin/zcat
GZIP?=		-9
GZIP_CMD?=	${LOCALBASE}/bin/gzip -nf ${GZIP}
.endif
HEAD?=		/usr/bin/head
ID?=		/usr/xpg4/bin/id
LDCONFIG?=	/usr/bin/true
LN?=		/usr/bin/ln
LS?=		/usr/bin/ls
MKDIR?=		/usr/bin/mkdir -p
MTREE?=		${ZOULARISBASE}/bin/mtree
MV?=		/usr/bin/mv
.if exists(/usr/bin/gpatch)
PATCH?=		/usr/bin/gpatch -b
.else
PATCH?=		${LOCALBASE}/bin/patch -b
.endif
PAX?=		/bin/pax
PKGLOCALEDIR?=	lib
RM?=		/usr/bin/rm
RMDIR?=		/usr/bin/rmdir
SED?=		/usr/bin/sed
SETENV?=	/usr/bin/env
SH?=		/bin/ksh
SORT?=		/usr/bin/sort
SU?=		/usr/bin/su
TAIL?=		/usr/xpg4/bin/tail
TEST?=		/usr/bin/test
TOUCH?=		/usr/bin/touch
TR?=		/usr/bin/tr
TRUE?=		/usr/bin/true
TYPE?=		/usr/bin/type
WC?=		/usr/bin/wc
XARGS?=		/usr/bin/xargs

DEF_UMASK?=	022
GROUPADD?=	/usr/sbin/groupadd
NOLOGIN?=	${FALSE}
USERADD?=	/usr/sbin/useradd

ROOT_USER?=	root
ROOT_GROUP?=	root

_DO_LIBINTL_CHECKS=	yes		# perform checks for valid libintl
_DO_SHLIB_CHECKS=	yes		# fixup PLIST for shared libs
_IMAKE_MAKE=	/usr/ccs/bin/make	# program which gets invoked by imake
_OPSYS_HAS_MANZ=	no		# no MANZ for gzipping of man pages
_PATCH_BACKUP_ARG= 	-z		# switch to patch(1) for backup file
_PREFORMATTED_MAN_DIR=	man		# directory where catman pages are
_USE_RPATH=		yes		# add rpath to LDFLAGS
