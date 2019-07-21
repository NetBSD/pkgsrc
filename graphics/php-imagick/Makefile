# $NetBSD: Makefile,v 1.20 2019/07/21 22:25:03 wiz Exp $

MODNAME=		imagick
PECL_VERSION=		3.4.3
CATEGORIES+=		graphics

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pecl.php.net/package/imagick/
COMMENT=		PHP extension for ImageMagick graphics library
PKGREVISION=		10
LICENSE=		php

CONFIGURE_ARGS+=	--with-imagick=${BUILDLINK_PREFIX.ImageMagick}

TEST_TARGET=		test

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
