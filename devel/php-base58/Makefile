# $NetBSD: Makefile,v 1.1 2021/03/11 13:18:46 tpaul Exp $

MODNAME=		base58
PECL_VERSION=		1.0.2
CATEGORIES=		devel

MAINTAINER=		tpaul@NetBSD.org
HOMEPAGE=		https://pecl.php.net/package/ast
LICENSE=		mit
COMMENT=		PHP extension for base58 encoding and decoding

CONFIGURE_ARGS+=	--with-base58=${PREFIX}

PHP_VERSIONS_INCOMPATIBLE=	56

TEST_TARGET=		test
TEST_ENV=		NO_INTERACTION=set

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
