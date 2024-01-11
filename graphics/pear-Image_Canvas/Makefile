# $NetBSD: Makefile,v 1.15 2024/01/11 14:33:18 taca Exp $

DISTNAME=	Image_Canvas-0.4.0
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pear.php.net/package/Image_Color/
COMMENT=	Common interface to image drawing, making image source code
LICENSE=	gnu-lgpl-v2.1

CONFLICTS=	php-pear-Image_Canvas-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Image_Color>=1.0.0:../../graphics/pear-Image_Color

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
