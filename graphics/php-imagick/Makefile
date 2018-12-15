# $NetBSD: Makefile,v 1.17 2018/12/15 17:05:29 taca Exp $

MODNAME=		imagick
PECL_VERSION=		3.4.3
CATEGORIES+=		graphics

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pecl.php.net/package/imagick/
COMMENT=		PHP extension for ImageMagick graphics library
PKGREVISION=		7
LICENSE=		php

CONFIGURE_ARGS+=	--with-imagick=${BUILDLINK_PREFIX.ImageMagick}

TEST_TARGET=		test

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
