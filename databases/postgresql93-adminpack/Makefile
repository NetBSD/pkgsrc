# $NetBSD: Makefile,v 1.5 2016/04/09 12:51:47 adam Exp $

PKGNAME=	${DISTNAME:C/-/93-adminpack-/}
COMMENT=	Admin pack module for pgAdmin management

DEPENDS+=	postgresql93-server>=${PKGVERSION_NOREV}:../../databases/postgresql93-server

.include "../../databases/postgresql93/Makefile.common"

BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		contrib/adminpack

.include "../../databases/postgresql93-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
