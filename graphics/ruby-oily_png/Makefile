# $NetBSD: Makefile,v 1.1 2012/09/16 06:38:26 taca Exp $

DISTNAME=	oily_png-1.0.2
CATEGORIES=	graphics

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://wiki.github.com/wvanbergen/oily_png
COMMENT=	Native mixin to speed up ChunkyPNG
LICENSE=	mit

DEPENDS+= ${RUBY_PKGPREFIX}-chunky_png>=1.2.1<1.3:../../graphics/ruby-chunky_png

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
