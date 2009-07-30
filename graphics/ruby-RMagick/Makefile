# $NetBSD: Makefile,v 1.63 2009/07/30 13:08:21 obache Exp $

DISTNAME=	rmagick-2.11.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rmagick/RMagick/}
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rmagick.rubyforge.org/
COMMENT=	Ruby binding to ImageMagick

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"

BUILDLINK_API_DEPENDS.ImageMagick+=	ImageMagick>=6.3.5.10

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
