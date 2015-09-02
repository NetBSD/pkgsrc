# $NetBSD: Makefile,v 1.1 2015/09/02 12:44:07 fhajny Exp $

PKGNAME=		${DISTNAME:S/sqlrelay/sqlrelay-nodejs/}
COMMENT=		node.js API for SQL Relay

.include "../../databases/sqlrelay/Makefile.common"

DEPENDS+=		nodejs-[0-9]*:../../lang/nodejs

LICENSE=		gnu-lgpl-v2

CONFIGURE_ARGS+=	--with-nodejs-prefix=${PREFIX}
CONFIGURE_ARGS+=	--disable-postgresql
CONFIGURE_ARGS+=	--disable-sqlite
CONFIGURE_ARGS+=	--disable-freetds
CONFIGURE_ARGS+=	--disable-mysql

BUILD_DIRS=		src/api/nodejs

.include "../../databases/sqlrelay/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
