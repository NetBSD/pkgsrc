# $NetBSD: Makefile,v 1.7 2016/10/15 13:55:10 taca Exp $

DISTNAME=	oily_png-1.2.1
CATEGORIES=	graphics

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	https://github.com/wvanbergen/chunky_png/wiki
COMMENT=	Native mixin to speed up ChunkyPNG
LICENSE=	mit

DEPENDS+= ${RUBY_PKGPREFIX}-chunky_png>=1.3.1<1.4:../../graphics/ruby-chunky_png

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
