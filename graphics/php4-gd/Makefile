# $NetBSD: Makefile,v 1.6 2001/10/24 22:11:02 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		gd
CATEGORIES+=		graphics
PHP_PKG_VERS=		nb1
COMMENT=		PHP4 extension for GD graphics library

USE_BUILDLINK_ONLY=	YES

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-freetype-dir=shared,${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-jpeg-dir=shared,${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-png-dir=shared,${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-xpm-dir=shared,${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-ttf=shared,${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--enable-${MODNAME}-native-ttf
CONFIGURE_ARGS+=	--without-t1lib

.include "../../graphics/gd/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
