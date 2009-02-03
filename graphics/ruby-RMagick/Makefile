# $NetBSD: Makefile,v 1.60 2009/02/03 12:44:52 obache Exp $

DISTNAME=	rmagick-2.9.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rmagick/RMagick/}
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rmagick.rubyforge.org/
COMMENT=	Ruby binding to ImageMagick

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"

BUILDLINK_API_DEPENDS.ImageMagick+=	ImageMagick>=6.3.0

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
