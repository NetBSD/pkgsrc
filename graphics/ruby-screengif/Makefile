# $NetBSD: Makefile,v 1.1 2018/11/16 00:16:15 schmonz Exp $

DISTNAME=	screengif-0.0.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	graphics

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://github.com/dergachev/screengif/
COMMENT=	Create animated gif screencasts
LICENSE=	mit

DEPENDS+=	ffmpeg4-[0-9]*:../../multimedia/ffmpeg4
DEPENDS+=	gifsicle-[0-9]*:../../graphics/gifsicle
DEPENDS+=	${RUBY_PKGPREFIX}-RMagick-[0-9]*:../../graphics/ruby-RMagick

USE_TOOLS+=	pkg-config

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
