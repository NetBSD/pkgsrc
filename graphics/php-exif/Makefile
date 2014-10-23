# $NetBSD: Makefile,v 1.13 2014/10/23 16:20:04 taca Exp $

MODNAME=		exif
PKGREVISION=		1
CATEGORIES+=		graphics
COMMENT=		PHP extension to extract information from EXIF headers

CONFIGURE_ARGS+=	--with-${MODNAME}=shared
USE_PHP_EXT_PATCHES=	yes

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
