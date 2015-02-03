# $NetBSD: Makefile,v 1.5 2015/02/03 14:31:21 taca Exp $

DISTNAME=	oily_png-1.1.2
CATEGORIES=	graphics

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://wiki.github.com/wvanbergen/oily_png
COMMENT=	Native mixin to speed up ChunkyPNG
LICENSE=	mit

DEPENDS+= ${RUBY_PKGPREFIX}-chunky_png>=1.3.1<1.4:../../graphics/ruby-chunky_png

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
