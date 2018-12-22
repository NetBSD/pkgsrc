# $NetBSD: Makefile,v 1.3 2018/12/22 17:20:51 taca Exp $

DISTNAME=	screengif-0.0.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	2
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
