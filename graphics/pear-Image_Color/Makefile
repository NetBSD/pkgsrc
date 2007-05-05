# $NetBSD: Makefile,v 1.6 2007/05/05 22:09:18 adrianp Exp $

DISTNAME=	Image_Color-1.0.2
PKGREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://pear.php.net/package/Image_Color/
COMMENT=	Manage and handles color data and conversions

CONFLICTS=	php-pear-Image_Color-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-gd-[0-9]*:../../graphics/php-gd

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
