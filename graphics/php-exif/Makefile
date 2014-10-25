# $NetBSD: Makefile,v 1.12.16.1 2014/10/25 15:55:51 tron Exp $

MODNAME=		exif
PKGREVISION=		1
CATEGORIES+=		graphics
COMMENT=		PHP extension to extract information from EXIF headers

CONFIGURE_ARGS+=	--with-${MODNAME}=shared
USE_PHP_EXT_PATCHES=	yes

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
