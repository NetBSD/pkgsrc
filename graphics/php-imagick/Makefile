# $NetBSD: Makefile,v 1.37 2021/12/08 16:05:03 adam Exp $

MODNAME=		imagick
PECL_VERSION=		3.5.1
CATEGORIES+=		graphics

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pecl.php.net/package/imagick/
COMMENT=		PHP extension for ImageMagick graphics library
PKGREVISION=		1
LICENSE=		php

CONFIGURE_ARGS+=	--with-imagick=${BUILDLINK_PREFIX.ImageMagick}

TEST_TARGET=		test

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
