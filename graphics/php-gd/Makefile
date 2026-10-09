# $NetBSD: Makefile,v 1.64 2026/10/09 10:57:42 jperkin Exp $

MODNAME=		gd
PKGREVISION=		16
CATEGORIES+=		graphics
COMMENT=		PHP extension for GD graphics library
LICENSE=		php

CONFLICTS=	php-gd-[0-9]*

FORCE_C_STD=	c99

.include "../../lang/php/phpversion.mk"

.if ${PHP_VER} < 74
CONFIGURE_ARGS+=	--with-${MODNAME}=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-jpeg-dir=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-png-dir=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-zlib-dir=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-freetype-dir=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--enable-${MODNAME}-native-ttf
CONFIGURE_ARGS+=	--enable-${MODNAME}-jis-conv
CONFIGURE_ARGS+=	--without-t1lib

USE_TOOLS+=		pkg-config
.else
CONFIGURE_ARGS+=	--with-external-gd
.endif

USE_PHP_EXT_PATCHES=	yes

.include "../../graphics/gd/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
