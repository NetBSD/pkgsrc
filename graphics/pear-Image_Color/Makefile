# $NetBSD: Makefile,v 1.14 2024/02/28 14:41:44 taca Exp $

DISTNAME=	Image_Color-1.0.6
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pear.php.net/package/Image_Color/
COMMENT=	Manage and handles color data and conversions
LICENSE=	gnu-lgpl-v2.1

CONFLICTS=	php-pear-Image_Color-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-gd-[0-9]*:../../graphics/php-gd

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
