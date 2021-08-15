# $NetBSD: Makefile,v 1.33 2021/08/15 14:24:02 wiz Exp $

MODNAME=		imagick
PECL_VERSION=		3.4.4
PKGREVISION=		9
CATEGORIES+=		graphics

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pecl.php.net/package/imagick/
COMMENT=		PHP extension for ImageMagick graphics library
LICENSE=		php

CONFIGURE_ARGS+=	--with-imagick=${BUILDLINK_PREFIX.ImageMagick}

TEST_TARGET=		test

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
