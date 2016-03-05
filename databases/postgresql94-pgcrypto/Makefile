# $NetBSD: Makefile,v 1.2 2016/03/05 11:28:17 jperkin Exp $

PKGNAME=	${DISTNAME:C/-/94-pgcrypto-/}
PKGREVISION=	1
COMMENT=	Module providing cryptographic functions for PostgreSQL

DEPENDS+=	postgresql94-server>=${PKGVERSION_NOREV}:../../databases/postgresql94-server

.include "../../databases/postgresql94/Makefile.common"

CONFIGURE_ARGS+=	--with-zlib
BUILD_MAKE_FLAGS=	USE_PGXS=1

BUILD_DIRS=		contrib/pgcrypto

.include "../../databases/postgresql94-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
