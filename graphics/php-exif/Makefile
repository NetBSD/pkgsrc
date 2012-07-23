# $NetBSD: Makefile,v 1.10.12.1 2012/07/23 18:24:33 tron Exp $

MODNAME=		exif
CATEGORIES+=		graphics
COMMENT=		PHP extension to extract information from EXIF headers

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-${MODNAME}=shared
USE_PHP_EXT_PATCHES=	yes

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
