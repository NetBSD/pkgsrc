# $NetBSD: Makefile,v 1.1 2015/01/14 21:01:18 adam Exp $

PKGNAME=	${DISTNAME:C/-/94-adminpack-/}
COMMENT=	Admin pack module for pgAdmin management

DEPENDS+=	postgresql94-server>=${PKGVERSION_NOREV}:../../databases/postgresql94-server

.include "../../databases/postgresql94/Makefile.common"

BUILD_MAKE_FLAGS=	USE_PGXS=1

BUILD_DIRS=		contrib/adminpack

.include "../../databases/postgresql94-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
