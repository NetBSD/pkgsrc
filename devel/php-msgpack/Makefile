# $NetBSD: Makefile,v 1.2 2024/06/28 17:36:05 adam Exp $

MODNAME=	msgpack
PECL_VERSION=	2.2.0
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
