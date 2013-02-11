# $NetBSD: Makefile,v 1.2 2013/02/11 03:14:36 taca Exp $

DISTNAME=	oily_png-1.0.3
CATEGORIES=	graphics

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://wiki.github.com/wvanbergen/oily_png
COMMENT=	Native mixin to speed up ChunkyPNG
LICENSE=	mit

DEPENDS+= ${RUBY_PKGPREFIX}-chunky_png>=1.2.1<1.3:../../graphics/ruby-chunky_png

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
