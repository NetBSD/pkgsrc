# $NetBSD: Makefile,v 1.7 2012/12/16 01:52:04 obache Exp $

PKGNAME=	${DISTNAME:C/-/84-pgcrypto-/}
PKGREVISION=	1
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
