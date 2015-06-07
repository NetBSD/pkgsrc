# $NetBSD: Makefile,v 1.15 2015/06/07 10:43:50 taca Exp $

DISTNAME=	mini_magick-4.2.7
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/minimagick/minimagick
COMMENT=	Ruby wrapper for ImageMagick command line
LICENSE=	mit

# MiniMagick uses mogrify(1) or gm(1) from ImageMagick.
DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick

pre-configure:
	${FIND} ${WRKSRC} -type f -exec ${CHMOD} -x {} \;

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
