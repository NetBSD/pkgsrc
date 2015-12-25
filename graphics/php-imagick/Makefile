# $NetBSD: Makefile,v 1.2 2015/12/25 01:18:10 taca Exp $

MODNAME=		imagick
PECL_VERSION=		3.1.2
CATEGORIES+=		graphics

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pecl.php.net/package/imagick/
COMMENT=		PHP extension for ImageMagick graphics library
LICENSE=		php

PHP_VERSIONS_ACCEPTED=	55 56

CONFIGURE_ARGS+=	--with-imagick=${BUILDLINK_PREFIX.ImageMagick}

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
