# $NetBSD: Makefile,v 1.4 2004/11/12 09:43:16 adam Exp $

MODNAME=		gd
CATEGORIES+=		graphics
COMMENT=		PHP extension for GD graphics library

USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--with-${MODNAME}	# use bundled libgd
CONFIGURE_ARGS+=	--with-jpeg-dir=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-png-dir=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-zlib-dir=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-ttf=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-freetype-dir=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--enable-${MODNAME}-native-ttf
CONFIGURE_ARGS+=	--enable-${MODNAME}-jis-conv
CONFIGURE_ARGS+=	--without-t1lib

.include "../../graphics/gd/buildlink3.mk"
.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
