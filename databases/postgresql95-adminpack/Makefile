# $NetBSD: Makefile,v 1.1 2016/02/25 21:37:36 tnn Exp $

PKGNAME=	${DISTNAME:C/-/95-adminpack-/}
COMMENT=	Admin pack module for pgAdmin management

DEPENDS+=	postgresql95-server>=${PKGVERSION_NOREV}:../../databases/postgresql95-server

.include "../../databases/postgresql95/Makefile.common"

BUILD_MAKE_FLAGS=	USE_PGXS=1

BUILD_DIRS=		contrib/adminpack

.include "../../databases/postgresql95-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
