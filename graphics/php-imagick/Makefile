# $NetBSD: Makefile,v 1.58 2024/05/16 06:15:03 wiz Exp $

MODNAME=		imagick
PECL_VERSION=		3.7.0
CATEGORIES+=		graphics

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pecl.php.net/package/imagick/
COMMENT=		PHP extension for ImageMagick graphics library
PKGREVISION=		17
LICENSE=		php

CONFIGURE_ARGS+=	--with-imagick=${BUILDLINK_PREFIX.ImageMagick}

TEST_TARGET=		test

PHP_VERSIONS_INCOMPATIBLE=	56

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
