# $NetBSD: Makefile,v 1.9 2013/02/09 11:19:10 adam Exp $

PKGNAME=	${DISTNAME:C/-/84-pgcrypto-/}
COMMENT=	Module providing cryptographic functions for PostgreSQL

DEPENDS+=	postgresql84-server>=${PKGVERSION_NOREV}:../../databases/postgresql84-server

.include "../../databases/postgresql84/Makefile.common"

CONFIGURE_ARGS+=	--with-zlib

BUILD_DIRS=		contrib/pgcrypto
BUILD_MAKE_FLAGS=	PGXS=1
REQD_DIRS+=		share/doc/postgresql/contrib
REQD_DIRS+=		share/postgresql/contrib

.include "../../databases/postgresql84-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
