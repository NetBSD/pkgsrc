# $NetBSD: Makefile,v 1.28 2021/02/16 13:12:39 adam Exp $

PKGNAME=	${DISTNAME:S/sqlrelay/sqlrelay-nodejs/}
COMMENT=	node.js API for SQL Relay

.include "../../databases/sqlrelay/Makefile.common"

USE_LANGUAGES+=		gnu++14

LICENSE=		gnu-lgpl-v2

BUILD_DEPENDS+=		npm-[0-9]*:../../lang/npm

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
.include "../../mk/bsd.pkg.mk"
