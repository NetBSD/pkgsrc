# $NetBSD: Makefile,v 1.7 2008/06/12 02:14:32 joerg Exp $

DISTNAME=	Image_Color-1.0.2
PKGREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://pear.php.net/package/Image_Color/
COMMENT=	Manage and handles color data and conversions

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-pear-Image_Color-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-gd-[0-9]*:../../graphics/php-gd

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
