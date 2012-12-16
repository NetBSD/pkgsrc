# $NetBSD: Makefile,v 1.8 2012/12/16 01:52:05 obache Exp $

PKGNAME=	${DISTNAME:C/-/90-pgcrypto-/}
PKGREVISION=	1
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
