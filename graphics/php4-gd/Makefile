# $NetBSD: Makefile,v 1.14 2003/08/31 19:55:46 jdolecek Exp $

MODNAME=		gd
CATEGORIES+=		graphics
PKGREVISION=		# empty
COMMENT=		PHP4 extension for GD graphics library

USE_BUILDLINK2=		YES
USE_X11=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}	# use bundled libgd
CONFIGURE_ARGS+=	--with-jpeg-dir=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-png-dir=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-zlib-dir=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-xpm-dir=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-ttf=${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--enable-${MODNAME}-native-ttf
CONFIGURE_ARGS+=	--enable-${MODNAME}-jis-conv
CONFIGURE_ARGS+=	--without-freetype-dir
CONFIGURE_ARGS+=	--without-t1lib

.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
