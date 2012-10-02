# $NetBSD: Makefile,v 1.4 2012/10/02 21:25:47 asau Exp $

PKGNAME=	${DISTNAME:C/-/91-pgcrypto-/}
COMMENT=	Module providing cryptographic functions for PostgreSQL

DEPENDS+=	postgresql91-server>=${PKGVERSION_NOREV}:../../databases/postgresql91-server

.include "../../databases/postgresql91/Makefile.common"

CONFIGURE_ARGS+=	--with-zlib
BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		contrib/pgcrypto

.include "../../databases/postgresql91-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
