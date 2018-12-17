# $NetBSD: Makefile,v 1.2 2018/12/17 15:58:59 taca Exp $

DISTNAME=	screengif-0.0.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	graphics

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://github.com/dergachev/screengif/
COMMENT=	Create animated gif screencasts
LICENSE=	mit

DEPENDS+=	ffmpeg4-[0-9]*:../../multimedia/ffmpeg4
DEPENDS+=	gifsicle-[0-9]*:../../graphics/gifsicle
DEPENDS+=	${RUBY_PKGPREFIX}-RMagick-[0-9]*:../../graphics/ruby-RMagick

USE_LANGUAGES=	# none
USE_TOOLS+=	pkg-config

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
