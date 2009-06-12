# $NetBSD: Makefile,v 1.2 2009/06/12 13:35:40 taca Exp $

DISTNAME=	mini_magick-1.2.3
PKGNAME=	${RUBYGEM_PKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mini_magick.rubyforge.org/
COMMENT=	Ruby wrapper for ImageMagick command line
LICENSE=	mit

# MiniMagick uses identify(1) and mogrify(1) from ImageMagick.
DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick
DEPENDS+=	hoe>=1.5.1:../../devel/hoe

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
