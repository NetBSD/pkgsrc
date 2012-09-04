# $NetBSD: Makefile,v 1.12 2012/09/04 16:06:09 taca Exp $

DISTNAME=	Image_Canvas-0.3.5
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pear.php.net/package/Image_Color/
COMMENT=	Common interface to image drawing, making image source code

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-pear-Image_Canvas-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Image_Color>=1.0.0:../../graphics/pear-Image_Color

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
