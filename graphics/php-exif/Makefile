# $NetBSD: Makefile,v 1.8.8.1 2011/02/23 19:12:53 tron Exp $

MODNAME=		exif
PKGREVISION=		2
CATEGORIES+=		graphics
COMMENT=		PHP extension to extract information from EXIF headers

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-${MODNAME}=shared
USE_PHP_EXT_PATCHES=	yes

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
