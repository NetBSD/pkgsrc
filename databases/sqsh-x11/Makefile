# $NetBSD: Makefile,v 1.2 2004/03/29 12:51:54 grant Exp $

PKGNAME=		sqsh-x11-2.1
COMMENT=		SQL shell for Sybase and MS-SQL servers (X11 support)

CONFLICTS+=		sqsh-[0-9]*
CONFLICTS+=		sqsh-motif-[0-9]*

USE_X11=		YES
CONFIGURE_ARGS+=	--with-x

PATCHDIR=		${.CURDIR}/../../databases/sqsh/patches
DISTINFO_FILE=		${.CURDIR}/../../databases/sqsh/distinfo
PLIST_SRC=		${.CURDIR}/../../databases/sqsh/PLIST
DESCR_SRC=		${.CURDIR}/../../databases/sqsh/DESCR

.include "../../databases/sqsh/Makefile.common"
