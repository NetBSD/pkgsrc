# $NetBSD: Makefile,v 1.48 2020/08/17 20:19:07 leot Exp $

MODNAME=		gd
CATEGORIES+=		graphics
COMMENT=		PHP extension for GD graphics library
PKGREVISION=		1

CONFLICTS=	php-gd-[0-9]*

.include "../../lang/php/phpversion.mk"

.if ${PKG_PHP_VERSION} < 74
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

.include "options.mk"

.include "../../graphics/gd/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
