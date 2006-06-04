# $NetBSD: Makefile,v 1.4 2006/06/04 16:26:54 joerg Exp $

DISTNAME=	Image_Graph-0.3.0dev4
CATEGORIES=	graphics

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE= 	http://pear.php.net/package/Image_Graph/
COMMENT=	Package for displaying (numerical) data as a graph/chart/plot

CONFLICTS=	php-pear-Image_Graph-[0-9]*

DEPENDS+=	${PHP_PKG_PREFIX}-pear-Image_Canvas>=0.2.1:../../graphics/pear-Image_Canvas
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Numbers_Roman-[0-9]*:../../math/pear-Numbers_Roman
DEPENDS+=	${PHP_PKG_PREFIX}-pear-Numbers_Words-[0-9]*:../../math/pear-Numbers_Words

.include "../../lang/php/pear.mk"
.include "../../mk/bsd.pkg.mk"
