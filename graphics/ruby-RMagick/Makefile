# $NetBSD: Makefile,v 1.50 2008/04/04 15:30:01 jlam Exp $

DISTNAME=	rmagick-2.3.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rmagick/RMagick/}
CATEGORIES=	graphics

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://rmagick.rubyforge.org/
COMMENT=	Ruby binding to ImageMagick

GEM_BUILD=	gemspec

.include "../../misc/rubygems/rubygem.mk"

BUILDLINK_API_DEPENDS.ImageMagick+=	ImageMagick>=6.3.0

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
