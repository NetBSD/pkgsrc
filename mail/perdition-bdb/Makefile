# $NetBSD: Makefile,v 1.5 2008/06/12 02:14:35 joerg Exp $
#

PKGREVISION=		3

PERDITION_COMMENT=	Berkeley DB user database module
PERDITION_PKGNAME=	bdb
BUILD_DIRS=		makebdb perdition/db/bdb

BDB_ACCEPTED=		db4

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bdb.buildlink3.mk"
.include "../../mail/perdition/buildlink3.mk"
.include "../perdition/Makefile.common"
