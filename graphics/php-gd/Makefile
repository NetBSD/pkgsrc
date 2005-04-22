# $NetBSD: Makefile,v 1.6.4.1 2005/04/22 14:17:32 salo Exp $

MODNAME=		gd
PKGREVISION=		# empty
CATEGORIES+=		graphics
COMMENT=		PHP extension for GD graphics library

USE_BUILDLINK3=		YES

# XXX we use bundled GD so that extension is usable also by non-threaded
# PHP, such as CLI/CGI version or ap-php on Apache 1.x.

CONFIGURE_ARGS+=	--with-${MODNAME}
CONFIGURE_ARGS+=	--with-jpeg-dir=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-png-dir=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-zlib-dir=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-freetype-dir=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--enable-${MODNAME}-native-ttf
CONFIGURE_ARGS+=	--enable-${MODNAME}-jis-conv
CONFIGURE_ARGS+=	--without-t1lib

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
