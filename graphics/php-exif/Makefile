# $NetBSD: Makefile,v 1.12 2012/10/06 14:11:13 asau Exp $

MODNAME=		exif
CATEGORIES+=		graphics
COMMENT=		PHP extension to extract information from EXIF headers

CONFIGURE_ARGS+=	--with-${MODNAME}=shared
USE_PHP_EXT_PATCHES=	yes

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
