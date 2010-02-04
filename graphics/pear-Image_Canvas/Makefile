# $NetBSD: Makefile,v 1.8 2010/02/04 16:36:05 joerg Exp $

DISTNAME=	Image_Canvas-0.2.4
PKGREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pear.php.net/package/Image_Color/
COMMENT=	Common interface to image drawing, making image source code

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-pear-Image_Canvas-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Image_Color>=1.0.0:../../graphics/pear-Image_Color

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
