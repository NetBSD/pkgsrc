# $NetBSD: Makefile,v 1.7 2013/02/09 11:19:14 adam Exp $

PKGNAME=	${DISTNAME:C/-/91-adminpack-/}
COMMENT=	Admin pack module for pgAdmin management

DEPENDS+=	postgresql91-server>=${PKGVERSION_NOREV}:../../databases/postgresql91-server

.include "../../databases/postgresql91/Makefile.common"

BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		contrib/adminpack

.include "../../databases/postgresql91-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
