# $NetBSD: Makefile,v 1.3 2012/07/01 19:49:24 morr Exp $

PKGNAME=	${DISTNAME:C/-/91-dblink-/}
COMMENT=	Dblink module for remote database connections

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	postgresql91-server>=${PKGVERSION_NOREV}:../../databases/postgresql91-server

.include "../../databases/postgresql91/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl
BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		contrib/dblink

.include "../../databases/postgresql91-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
