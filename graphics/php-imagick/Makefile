# $NetBSD: Makefile,v 1.5 2016/06/29 09:06:22 fhajny Exp $

MODNAME=		imagick
PECL_VERSION=		3.4.2
CATEGORIES+=		graphics

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pecl.php.net/package/imagick/
COMMENT=		PHP extension for ImageMagick graphics library
LICENSE=		php

PHP_VERSIONS_ACCEPTED=	55 56 70

CONFIGURE_ARGS+=	--with-imagick=${BUILDLINK_PREFIX.ImageMagick}

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
