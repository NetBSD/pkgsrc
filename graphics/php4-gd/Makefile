# $NetBSD: Makefile,v 1.13 2003/06/23 10:01:34 adam Exp $

MODNAME=		gd
CATEGORIES+=		graphics
PKGREVISION=		1
COMMENT=		PHP4 extension for GD graphics library

PATCHFILES+=		php-4.2.3-gd-2.0.8.patch
PATCH_DIST_STRIP=	-p3
SITES_php-4.2.3-gd-2.0.8.patch=	http://www.boutell.com/gd/

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
