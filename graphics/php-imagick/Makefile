# $NetBSD: Makefile,v 1.79 2026/01/23 05:42:22 wiz Exp $

MODNAME=		imagick
PECL_VERSION=		3.8.1
CATEGORIES+=		graphics

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://pecl.php.net/package/imagick
COMMENT=		PHP extension for ImageMagick graphics library
LICENSE=		php

CONFIGURE_ARGS+=	--with-imagick=${BUILDLINK_PREFIX.ImageMagick}

TEST_TARGET=		test

PHP_VERSIONS_INCOMPATIBLE=	56

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
