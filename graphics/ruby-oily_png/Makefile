# $NetBSD: Makefile,v 1.6 2015/06/07 10:47:57 taca Exp $

DISTNAME=	oily_png-1.2.0
CATEGORIES=	graphics

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://github.com/wvanbergen/chunky_png/wiki
COMMENT=	Native mixin to speed up ChunkyPNG
LICENSE=	mit

DEPENDS+= ${RUBY_PKGPREFIX}-chunky_png>=1.3.1<1.4:../../graphics/ruby-chunky_png

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
