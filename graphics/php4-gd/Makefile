# $NetBSD: Makefile,v 1.10 2002/03/13 17:37:15 fredb Exp $

MODNAME=		gd
CATEGORIES+=		graphics
PKGREVISION=		2
COMMENT=		PHP4 extension for GD graphics library

USE_BUILDLINK_ONLY=	YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-jpeg-dir=shared,${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-png-dir=shared,${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-xpm-dir=shared,${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--with-ttf=shared,${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--enable-${MODNAME}-native-ttf
CONFIGURE_ARGS+=	--without-freetype-dir
CONFIGURE_ARGS+=	--without-t1lib

.include "../../graphics/gd/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
