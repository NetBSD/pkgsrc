# $NetBSD: Makefile,v 1.14 2013/02/09 11:19:08 adam Exp $

PKGNAME=	${DISTNAME:C/-/83-adminpack-/}
COMMENT=	Admin pack module for pgAdmin management

DEPENDS+=	postgresql83-server>=${PKGVERSION_NOREV}:../../databases/postgresql83-server

.include "../../databases/postgresql83/Makefile.common"

BUILD_DIRS=		contrib/adminpack
BUILD_MAKE_FLAGS=	PGXS=1
REQD_DIRS+=		share/doc/postgresql/contrib
REQD_DIRS+=		share/postgresql/contrib

.include "../../databases/postgresql83-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
