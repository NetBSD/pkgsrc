# $NetBSD: Makefile,v 1.6 2008/09/07 11:24:28 wiz Exp $
#

PKGREVISION=		4

PERDITION_COMMENT=	Berkeley DB user database module
PERDITION_PKGNAME=	bdb
BUILD_DIRS=		makebdb perdition/db/bdb

BDB_ACCEPTED=		db4

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bdb.buildlink3.mk"
.include "../../mail/perdition/buildlink3.mk"
.include "../perdition/Makefile.common"
