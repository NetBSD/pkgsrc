# $NetBSD: Makefile,v 1.11 2017/08/24 20:03:09 adam Exp $

PKGNAME=		${DISTNAME:S/sqlrelay/sqlrelay-nodejs/}
PKGREVISION=		2
COMMENT=		node.js API for SQL Relay

.include "../../databases/sqlrelay/Makefile.common"

USE_LANGUAGES+=		c++11

DEPENDS+=		nodejs-[0-9]*:../../lang/nodejs

LICENSE=		gnu-lgpl-v2

CONFIGURE_ARGS+=	--with-nodejs-prefix=${PREFIX}
CONFIGURE_ARGS+=	--disable-postgresql
CONFIGURE_ARGS+=	--disable-sqlite
CONFIGURE_ARGS+=	--disable-freetds
CONFIGURE_ARGS+=	--disable-mysql

BUILD_DIRS=		src/api/nodejs

# Benign reference inside an object file
CHECK_WRKREF_SKIP+=	lib/node_modules/sqlrelay/sqlrelay.node

.include "../../databases/sqlrelay/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
