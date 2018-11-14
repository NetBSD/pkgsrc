# $NetBSD: Makefile,v 1.111 2018/11/14 22:21:45 kleink Exp $

DISTNAME=	rmagick-2.16.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rmagick/RMagick/}
PKGREVISION=	8
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rmagick/rmagick
COMMENT=	Ruby binding to ImageMagick
LICENSE=	mit

USE_TOOLS+=	pkg-config

USE_GCC_RUNTIME=	yes

.include "../../lang/ruby/gem.mk"

BUILDLINK_API_DEPENDS.ImageMagick6+=	ImageMagick6>=6.3.5.10

.include "../../graphics/ImageMagick6/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
