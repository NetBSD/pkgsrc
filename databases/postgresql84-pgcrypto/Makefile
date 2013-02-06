# $NetBSD: Makefile,v 1.8 2013/02/06 23:21:56 jperkin Exp $

PKGNAME=	${DISTNAME:C/-/84-pgcrypto-/}
PKGREVISION=	2
COMMENT=	Module providing cryptographic functions for PostgreSQL

DEPENDS+=	postgresql84-server>=${PKGVERSION_NOREV}:../../databases/postgresql84-server

.include "../../databases/postgresql84/Makefile.common"

CONFIGURE_ARGS+=	--with-zlib

BUILD_DIRS=		contrib/pgcrypto
BUILD_MAKE_FLAGS=	PGXS=1
REQD_DIRS+=		${PG_SUBPREFIX}share/doc/postgresql/contrib
REQD_DIRS+=		${PG_SUBPREFIX}share/postgresql/contrib

.include "../../databases/postgresql84-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
