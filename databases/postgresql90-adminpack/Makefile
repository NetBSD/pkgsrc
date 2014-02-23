# $NetBSD: Makefile,v 1.12 2014/02/23 11:25:51 adam Exp $

PKGNAME=	${DISTNAME:C/-/90-adminpack-/}
COMMENT=	Admin pack module for pgAdmin management

DEPENDS+=	postgresql90-server>=${PKGVERSION_NOREV}:../../databases/postgresql90-server

.include "../../databases/postgresql90/Makefile.common"

BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		contrib/adminpack
REQD_DIRS+=		share/doc/postgresql/contrib
REQD_DIRS+=		share/postgresql/contrib

.include "../../databases/postgresql90-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
