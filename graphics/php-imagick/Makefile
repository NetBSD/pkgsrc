# $NetBSD: Makefile,v 1.7 2017/02/28 15:20:06 ryoon Exp $

MODNAME=		imagick
PECL_VERSION=		3.4.2
CATEGORIES+=		graphics

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://pecl.php.net/package/imagick/
COMMENT=		PHP extension for ImageMagick graphics library
PKGREVISION=		1
LICENSE=		php

PHP_VERSIONS_ACCEPTED=	56 70

CONFIGURE_ARGS+=	--with-imagick=${BUILDLINK_PREFIX.ImageMagick}

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
