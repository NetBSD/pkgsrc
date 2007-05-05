# $NetBSD: Makefile,v 1.6 2007/05/05 22:09:18 adrianp Exp $

DISTNAME=	Image_Canvas-0.2.4
PKGREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://pear.php.net/package/Image_Color/
COMMENT=	Common interface to image drawing, making image source code

CONFLICTS=	php-pear-Image_Canvas-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Image_Color>=1.0.0:../../graphics/pear-Image_Color

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
