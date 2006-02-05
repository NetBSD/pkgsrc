# $NetBSD: Makefile,v 1.2 2006/02/05 23:09:57 joerg Exp $
#

PKGREVISION=		1

PERDITION_COMMENT=	Berkeley DB user database module
PERDITION_PKGNAME=	bdb
BUILD_DIRS=		makebdb perdition/db/bdb

BDB_ACCEPTED=		db4

.include "../../mk/bdb.buildlink3.mk"
.include "../../mail/perdition/buildlink3.mk"
.include "../perdition/Makefile.common"
