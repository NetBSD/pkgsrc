# $NetBSD: Makefile,v 1.5.2.1 2012/07/04 07:46:09 tron Exp $

PKGNAME=	${DISTNAME:C/-/90-dblink-/}
COMMENT=	Dblink module for remote database connections

PKG_DESTDIR_SUPPORT=	user-destdir

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
