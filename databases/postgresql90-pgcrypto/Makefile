# $NetBSD: Makefile,v 1.6 2012/07/01 19:42:07 morr Exp $

PKGNAME=	${DISTNAME:C/-/90-pgcrypto-/}
COMMENT=	Module providing cryptographic functions for PostgreSQL

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	postgresql90-server>=${PKGVERSION_NOREV}:../../databases/postgresql90-server

.include "../../databases/postgresql90/Makefile.common"

CONFIGURE_ARGS+=	--with-zlib
BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		contrib/pgcrypto
REQD_DIRS+=		${PG_SUBPREFIX}share/doc/postgresql/contrib
REQD_DIRS+=		${PG_SUBPREFIX}share/postgresql/contrib

.include "../../databases/postgresql90-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
