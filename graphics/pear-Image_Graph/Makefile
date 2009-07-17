# $NetBSD: Makefile,v 1.7 2009/07/17 18:00:16 adrianp Exp $

DISTNAME=	Image_Graph-0.3.0dev4
PKGREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pear.php.net/package/Image_Graph/
COMMENT=	Package for displaying (numerical) data as a graph/chart/plot

CONFLICTS=	php-pear-Image_Graph-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Image_Canvas>=0.2.1:../../graphics/pear-Image_Canvas
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Numbers_Roman-[0-9]*:../../math/pear-Numbers_Roman
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Numbers_Words-[0-9]*:../../math/pear-Numbers_Words

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
