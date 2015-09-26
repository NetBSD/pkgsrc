# $NetBSD: Makefile,v 1.99 2015/09/26 15:04:44 taca Exp $

DISTNAME=	rmagick-2.15.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rmagick/RMagick/}
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rmagick/rmagick
COMMENT=	Ruby binding to ImageMagick
LICENSE=	mit

USE_TOOLS+=	pkg-config

USE_GCC_RUNTIME=	yes

.include "../../lang/ruby/gem.mk"

BUILDLINK_API_DEPENDS.ImageMagick+=	ImageMagick>=6.3.5.10

.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
