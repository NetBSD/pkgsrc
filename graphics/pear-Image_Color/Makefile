# $NetBSD: Makefile,v 1.9 2010/02/06 15:50:21 taca Exp $

DISTNAME=	Image_Color-1.0.3
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pear.php.net/package/Image_Color/
COMMENT=	Manage and handles color data and conversions

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=	php-pear-Image_Color-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-gd-[0-9]*:../../graphics/php-gd

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
