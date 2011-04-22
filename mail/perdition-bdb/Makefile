# $NetBSD: Makefile,v 1.9 2011/04/22 13:44:04 obache Exp $

PKGREVISION=		2
PERDITION_COMMENT=	Berkeley DB user database module
PERDITION_PKGNAME=	bdb
BUILD_DIRS=		makebdb perdition/db/bdb

BDB_ACCEPTED=		db4 db5

PKG_DESTDIR_SUPPORT=	user-destdir

BUILDLINK_TRANSFORM+=	l:db:${BDB_TYPE}
.include "../../mk/bdb.buildlink3.mk"
.include "../../mail/perdition/buildlink3.mk"
.include "../../mail/perdition/Makefile.common"
