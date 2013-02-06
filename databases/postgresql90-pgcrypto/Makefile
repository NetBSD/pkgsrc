# $NetBSD: Makefile,v 1.9 2013/02/06 23:21:57 jperkin Exp $

PKGNAME=	${DISTNAME:C/-/90-pgcrypto-/}
PKGREVISION=	2
COMMENT=	Module providing cryptographic functions for PostgreSQL

DEPENDS+=	postgresql90-server>=${PKGVERSION_NOREV}:../../databases/postgresql90-server

.include "../../databases/postgresql90/Makefile.common"

CONFIGURE_ARGS+=	--with-zlib
BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		contrib/pgcrypto
REQD_DIRS+=		${PG_SUBPREFIX}share/doc/postgresql/contrib
REQD_DIRS+=		${PG_SUBPREFIX}share/postgresql/contrib

.include "../../databases/postgresql90-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
