# $NetBSD: Makefile,v 1.9 2013/02/06 23:21:57 jperkin Exp $

PKGNAME=	${DISTNAME:C/-/90-adminpack-/}
PKGREVISION=	2
COMMENT=	Admin pack module for pgAdmin management

DEPENDS+=	postgresql90-server>=${PKGVERSION_NOREV}:../../databases/postgresql90-server

.include "../../databases/postgresql90/Makefile.common"

BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		contrib/adminpack
REQD_DIRS+=		${PG_SUBPREFIX}share/doc/postgresql/contrib
REQD_DIRS+=		${PG_SUBPREFIX}share/postgresql/contrib

.include "../../databases/postgresql90-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
