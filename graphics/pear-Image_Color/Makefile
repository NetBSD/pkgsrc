# $NetBSD: Makefile,v 1.13 2019/07/03 07:28:22 nia Exp $

DISTNAME=	Image_Color-1.0.4
PKGREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pear.php.net/package/Image_Color/
COMMENT=	Manage and handles color data and conversions
LICENSE=	gnu-lgpl-v2.1

CONFLICTS=	php-pear-Image_Color-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-gd-[0-9]*:../../graphics/php-gd

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
