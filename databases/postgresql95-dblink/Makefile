# $NetBSD: Makefile,v 1.1 2016/02/25 21:37:36 tnn Exp $

PKGNAME=	${DISTNAME:C/-/95-dblink-/}
COMMENT=	Dblink module for remote database connections

DEPENDS+=	postgresql95-server>=${PKGVERSION_NOREV}:../../databases/postgresql95-server

.include "../../databases/postgresql95/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl
BUILD_MAKE_FLAGS=	USE_PGXS=1

BUILD_DIRS=		contrib/dblink

.include "../../databases/postgresql95-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
