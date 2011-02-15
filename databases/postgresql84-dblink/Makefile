# $NetBSD: Makefile,v 1.3 2011/02/15 08:14:16 adam Exp $

PKGNAME=	${DISTNAME:C/-/84-dblink-/}
COMMENT=	dblink module for remote database connections

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	postgresql84-server>=${PKGVERSION_NOREV}:../../databases/postgresql84-server

.include "../../databases/postgresql84/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl
BUILD_DIRS=		src/interfaces/libpq
BUILD_DIRS+=		contrib/dblink
BUILD_MAKE_FLAGS=	PGXS=1
INSTALL_DIRS=		contrib/dblink
REQD_DIRS+=		share/doc/postgresql/contrib
REQD_DIRS+=		share/postgresql/contrib

.include "../../databases/postgresql84-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
