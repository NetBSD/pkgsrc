# $NetBSD: Makefile,v 1.75 2011/01/13 13:38:20 wiz Exp $

DISTNAME=	rmagick-2.13.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rmagick/RMagick/}
PKGREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rmagick.rubyforge.org/
COMMENT=	Ruby binding to ImageMagick
LICENSE=	mit

.include "../../lang/ruby/gem.mk"

BUILDLINK_API_DEPENDS.ImageMagick+=	ImageMagick>=6.3.5.10

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
