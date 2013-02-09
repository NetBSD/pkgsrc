# $NetBSD: Makefile,v 1.7 2013/02/09 11:19:15 adam Exp $

PKGNAME=	${DISTNAME:C/-/91-dblink-/}
COMMENT=	Dblink module for remote database connections

DEPENDS+=	postgresql91-server>=${PKGVERSION_NOREV}:../../databases/postgresql91-server

.include "../../databases/postgresql91/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl
BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		contrib/dblink

.include "../../databases/postgresql91-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
