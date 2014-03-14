# $NetBSD: Makefile,v 1.4 2014/03/14 17:13:14 taca Exp $

DISTNAME=	oily_png-1.1.1
CATEGORIES=	graphics

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://wiki.github.com/wvanbergen/oily_png
COMMENT=	Native mixin to speed up ChunkyPNG
LICENSE=	mit

DEPENDS+= ${RUBY_PKGPREFIX}-chunky_png>=1.3.0<1.4:../../graphics/ruby-chunky_png

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
