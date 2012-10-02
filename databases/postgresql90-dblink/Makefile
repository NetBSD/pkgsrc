# $NetBSD: Makefile,v 1.7 2012/10/02 21:25:44 asau Exp $

PKGNAME=	${DISTNAME:C/-/90-dblink-/}
COMMENT=	Dblink module for remote database connections

DEPENDS+=	postgresql90-server>=${PKGVERSION_NOREV}:../../databases/postgresql90-server

.include "../../databases/postgresql90/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl
BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		src/interfaces/libpq
BUILD_DIRS+=		contrib/dblink
INSTALL_DIRS=		contrib/dblink
REQD_DIRS+=		${PG_SUBPREFIX}share/doc/postgresql/contrib
REQD_DIRS+=		${PG_SUBPREFIX}share/postgresql/contrib

.include "../../databases/postgresql90-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
