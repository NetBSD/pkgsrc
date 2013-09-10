# $NetBSD: Makefile,v 1.1 2013/09/10 15:32:32 adam Exp $

PKGNAME=	${DISTNAME:C/-/93-adminpack-/}
COMMENT=	Admin pack module for pgAdmin management

DEPENDS+=	postgresql93-server>=${PKGVERSION_NOREV}:../../databases/postgresql93-server

.include "../../databases/postgresql93/Makefile.common"

BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		contrib/adminpack

.include "../../databases/postgresql93-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
