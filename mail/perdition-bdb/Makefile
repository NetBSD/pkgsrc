# $NetBSD: Makefile,v 1.12 2020/12/04 04:56:01 riastradh Exp $

PKGREVISION=		4
PERDITION_COMMENT=	Berkeley DB user database module
PERDITION_PKGNAME=	bdb
BUILD_DIRS=		makebdb perdition/db/bdb

BDB_ACCEPTED=		db4 db5

BUILDLINK_TRANSFORM+=	l:db:${BDB_TYPE}
.include "../../mk/bdb.buildlink3.mk"
.include "../../mail/perdition/buildlink3.mk"
.include "../../mail/perdition/Makefile.common"
