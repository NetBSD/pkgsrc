# $NetBSD: defs.NetBSD.mk,v 1.16 2001/11/21 13:54:14 agc Exp $
#
# Variable definitions for the NetBSD operating system.

AWK?=		/usr/bin/awk
BASENAME?=	/usr/bin/basename
CAT?=		/bin/cat
CHMOD?=		/bin/chmod
CHOWN?=		/usr/sbin/chown
CHGRP?=		/usr/bin/chgrp
CMP?=		/usr/bin/cmp
CP?=		/bin/cp
CUT?=		/usr/bin/cut
DC?=		/usr/bin/dc
DIRNAME?=	/usr/bin/dirname
ECHO?=		echo				# Shell builtin
EGREP?=		/usr/bin/egrep
FALSE?=		false				# Shell builtin
FILE_CMD?=	/usr/bin/file
FIND?=		/usr/bin/find
GREP?=		/usr/bin/grep
GTAR?=		/usr/bin/tar
GUNZIP_CMD?=	/usr/bin/gunzip -f
GZCAT?=		/usr/bin/gzcat
GZIP?=		-9
GZIP_CMD?=	/usr/bin/gzip -nf ${GZIP}
HEAD?=		/usr/bin/head
ID?=		/usr/bin/id
LDCONFIG?=	/sbin/ldconfig
LN?=		/bin/ln
LS?=		/bin/ls
MKDIR?=		/bin/mkdir -p
MTREE?=		/usr/sbin/mtree
MV?=		/bin/mv
PATCH?=		/usr/bin/patch
PAX?=		/bin/pax
PKGLOCALEDIR?=	share
RM?=		/bin/rm
RMDIR?=		/bin/rmdir
SED?=		/usr/bin/sed
SETENV?=	/usr/bin/env
SH?=		/bin/sh
SORT?=		/usr/bin/sort
SU?=		/usr/bin/su
TAIL?=		/usr/bin/tail
TEST?=		test				# Shell builtin
TOUCH?=		/usr/bin/touch
TR?=		/usr/bin/tr
TRUE?=		true				# Shell builtin
TYPE?=		type				# Shell builtin
WC?=		/usr/bin/wc
XARGS?=		/usr/bin/xargs

.if exists(/usr/sbin/user)
USERADD?=	/usr/sbin/useradd
GROUPADD?=	/usr/sbin/groupadd
.else
USERADD?=	${LOCALBASE}/sbin/useradd
GROUPADD?=	${LOCALBASE}/sbin/groupadd
.if defined(USE_USERADD) || defined(USE_GROUPADD)
DEPENDS+=	user>=20000313:../../sysutils/user
.endif
.endif

DEF_UMASK?=	0022
MOTIF_TYPE_DEFAULT?=	openmotif	# default 2.0 compatible libs type
MOTIF12_TYPE_DEFAULT?=	lesstif12	# default 1.2 compatible libs type
NOLOGIN?=	/sbin/nologin

ROOT_USER?=	root
ROOT_GROUP?=	wheel

_DO_LIBINTL_CHECKS=	yes	# perform checks for valid libintl
_DO_SHLIB_CHECKS=	yes	# fixup PLIST for shared libs/run ldconfig
_IMAKE_MAKE=		${MAKE}	# program which gets invoked by imake
_OPSYS_HAS_MANZ=	yes	# MANZ controls gzipping of man pages
_PATCH_BACKUP_ARG=	-b	# switch to patch(1) to provide a backup file
_PREFORMATTED_MAN_DIR=	cat	# directory where catman pages are
_USE_RPATH=		yes	# add rpath to LDFLAGS
