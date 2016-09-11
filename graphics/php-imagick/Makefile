# $NetBSD: Makefile,v 1.6 2016/09/11 17:03:26 taca Exp $

MODNAME=		imagick
PECL_VERSION=		3.4.2
CATEGORIES+=		graphics

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pecl.php.net/package/imagick/
COMMENT=		PHP extension for ImageMagick graphics library
LICENSE=		php

PHP_VERSIONS_ACCEPTED=	56 70

CONFIGURE_ARGS+=	--with-imagick=${BUILDLINK_PREFIX.ImageMagick}

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
