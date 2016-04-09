# $NetBSD: Makefile,v 1.3 2016/04/09 12:51:49 adam Exp $

PKGNAME=	${DISTNAME:C/-/95-adminpack-/}
COMMENT=	Admin pack module for pgAdmin management

DEPENDS+=	postgresql95-server>=${PKGVERSION_NOREV}:../../databases/postgresql95-server

.include "../../databases/postgresql95/Makefile.common"

BUILD_MAKE_FLAGS=	USE_PGXS=1

BUILD_DIRS=		contrib/adminpack

.include "../../databases/postgresql95-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
