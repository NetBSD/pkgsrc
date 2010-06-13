# $NetBSD: Makefile,v 1.72 2010/06/13 22:44:43 wiz Exp $

DISTNAME=	rmagick-2.12.2
PKGREVISION=	4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rmagick/RMagick/}
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rmagick.rubyforge.org/
COMMENT=	Ruby binding to ImageMagick
LICENSE=	mit

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"

BUILDLINK_API_DEPENDS.ImageMagick+=	ImageMagick>=6.3.5.10

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
