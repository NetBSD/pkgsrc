# $NetBSD: defs.NetBSD.mk,v 1.1 2001/06/12 12:49:55 jlam Exp $
#
# Variable definitions for the NetBSD operating system.

AWK?=		/usr/bin/awk
BASENAME?=	/usr/bin/basename
CAT?=		/bin/cat
CHMOD?=		/bin/chmod
CHOWN?=		/usr/sbin/chown
CHGRP?=		/usr/bin/chgrp
CP?=		/bin/cp
CUT?=		/usr/bin/cut
DC?=		/usr/bin/dc
ECHO?=		echo				# Shell builtin
EGREP?=		/usr/bin/egrep
FALSE?=		false				# Shell builtin
FILE?=		/usr/bin/file
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
SU?=		/usr/bin/su
TAIL?=		/usr/bin/tail
TEST?=		test				# Shell builtin
TOUCH?=		/usr/bin/touch
TR?=		/usr/bin/tr
TRUE?=		true				# Shell builtin
TYPE?=		type				# Shell builtin
XARGS?=		/usr/bin/xargs
