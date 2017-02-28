# $NetBSD: Makefile,v 1.40 2017/02/28 15:20:06 ryoon Exp $

MODNAME=		gd
CATEGORIES+=		graphics
COMMENT=		PHP extension for GD graphics library
PKGREVISION=		1

CONFLICTS=	php-gd-[0-9]*

# XXX we use bundled GD so that extension is usable also by non-threaded
# PHP, such as CLI/CGI version or ap-php on Apache 1.x.

CONFIGURE_ARGS+=	--with-${MODNAME}=${BUILDLINK_DIR:Q}
CONFIGURE_ARGS+=	--with-jpeg-dir=${BUILDLINK_DIR:Q}
CONFIGURE_ARGS+=	--with-png-dir=${BUILDLINK_DIR:Q}
CONFIGURE_ARGS+=	--with-zlib-dir=${BUILDLINK_DIR:Q}
CONFIGURE_ARGS+=	--with-freetype-dir=${BUILDLINK_DIR:Q}
CONFIGURE_ARGS+=	--enable-${MODNAME}-native-ttf
CONFIGURE_ARGS+=	--enable-${MODNAME}-jis-conv
CONFIGURE_ARGS+=	--without-t1lib

USE_PHP_EXT_PATCHES=	yes

.include "options.mk"

.include "../../graphics/gd/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
