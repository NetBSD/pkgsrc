# $NetBSD: Makefile,v 1.4 2026/07/04 06:47:07 taca Exp $

MODNAME=	msgpack
PECL_VERSION=	3.0.1
CATEGORIES+=	devel

MAINTAINER=	tpaul@NetBSD.org
HOMEPAGE=	https://pecl.php.net/package/msgpack
COMMENT=	PHP extension for interfacing with MessagePack
LICENSE=	modified-bsd

PHP_VERSIONS_INCOMPATIBLE=	56

TEST_TARGET=	test
TEST_ENV=	NO_INTERACTION=set

.include "../../devel/msgpack/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
