# $NetBSD: Makefile,v 1.3 2013/03/11 09:18:28 taca Exp $

DISTNAME=	oily_png-1.1.0
CATEGORIES=	graphics

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://wiki.github.com/wvanbergen/oily_png
COMMENT=	Native mixin to speed up ChunkyPNG
LICENSE=	mit

DEPENDS+= ${RUBY_PKGPREFIX}-chunky_png>=1.2.7<1.3:../../graphics/ruby-chunky_png

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
