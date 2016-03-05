# $NetBSD: Makefile,v 1.10 2016/03/05 11:28:13 jperkin Exp $

PKGNAME=	${DISTNAME:C/-/91-dblink-/}
PKGREVISION=	1
COMMENT=	Dblink module for remote database connections

DEPENDS+=	postgresql91-server>=${PKGVERSION_NOREV}:../../databases/postgresql91-server

.include "../../databases/postgresql91/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl
BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		contrib/dblink

.include "../../databases/postgresql91-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
