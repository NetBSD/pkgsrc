# $NetBSD: Makefile,v 1.11 2014/02/12 23:17:41 tron Exp $

PKGNAME=	${DISTNAME:C/-/90-dblink-/}
PKGREVISION=	1
COMMENT=	Dblink module for remote database connections

DEPENDS+=	postgresql90-server>=${PKGVERSION_NOREV}:../../databases/postgresql90-server

.include "../../databases/postgresql90/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl
BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		src/interfaces/libpq
BUILD_DIRS+=		contrib/dblink
INSTALL_DIRS=		contrib/dblink
REQD_DIRS+=		share/doc/postgresql/contrib
REQD_DIRS+=		share/postgresql/contrib

.include "../../databases/postgresql90-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
