# $NetBSD: Makefile,v 1.4 2016/03/05 11:28:15 jperkin Exp $

PKGNAME=	${DISTNAME:C/-/93-dblink-/}
PKGREVISION=	1
COMMENT=	Dblink module for remote database connections

DEPENDS+=	postgresql93-server>=${PKGVERSION_NOREV}:../../databases/postgresql93-server

.include "../../databases/postgresql93/Makefile.common"

CONFIGURE_ARGS+=	--with-openssl
BUILD_MAKE_FLAGS=	PGXS=1

BUILD_DIRS=		contrib/dblink

.include "../../databases/postgresql93-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
