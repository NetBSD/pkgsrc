# $NetBSD: Makefile,v 1.31 2021/09/22 21:19:28 mef Exp $

PKGNAME=	${DISTNAME:S/sqlrelay/sqlrelay-nodejs/}
PKGREVISION=	1
COMMENT=	node.js API for SQL Relay

.include "../../databases/sqlrelay/Makefile.common"

USE_LANGUAGES+=		gnu++14

LICENSE=		gnu-lgpl-v2

BUILD_DEPENDS+=		npm-[0-9]*:../../lang/npm
DEPENDS+=		http-parser-[0-9]*:../../www/http-parser

NODE_VERSIONS_ACCEPTED=	12 10

CONFIGURE_ARGS+=	--with-nodejs-prefix=${BUILDLINK_PREFIX.nodejs}
CONFIGURE_ARGS+=	--disable-postgresql
CONFIGURE_ARGS+=	--disable-sqlite
CONFIGURE_ARGS+=	--disable-freetds
CONFIGURE_ARGS+=	--disable-mysql

BUILD_DIRS=		src/api/nodejs

# Benign reference inside an object file
CHECK_WRKREF_SKIP+=	lib/node_modules/sqlrelay/sqlrelay.node

.include "../../databases/sqlrelay/buildlink3.mk"
.include "../../lang/nodejs/nodeversion.mk"
.include "../../lang/python/tool.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
