# $NetBSD: Makefile,v 1.3 2025/02/08 03:41:14 taca Exp $

MODNAME=	msgpack
PECL_VERSION=	2.2.0
PKGREVISION=	1
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
