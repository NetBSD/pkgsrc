# $NetBSD: Makefile,v 1.11 2002/09/22 10:19:57 jlam Exp $

MODNAME=		gd
CATEGORIES+=		graphics
PKGREVISION=		2
COMMENT=		PHP4 extension for GD graphics library

USE_BUILDLINK2=		YES
USE_X11=		YES

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.gd}
CONFIGURE_ARGS+=	--with-jpeg-dir=shared,${BUILDLINK_PREFIX.jpeg}
CONFIGURE_ARGS+=	--with-png-dir=shared,${BUILDLINK_PREFIX.png}
CONFIGURE_ARGS+=	--with-xpm-dir=shared,${BUILDLINK_PREFIX.xpm}
CONFIGURE_ARGS+=	--with-ttf=shared,${BUILDLINK_PREFIX.freetype}
CONFIGURE_ARGS+=	--enable-${MODNAME}-native-ttf
CONFIGURE_ARGS+=	--without-freetype-dir
CONFIGURE_ARGS+=	--without-t1lib

.include "../../graphics/gd/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
