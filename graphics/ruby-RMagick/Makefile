# $NetBSD: Makefile,v 1.118 2019/11/02 15:02:05 taca Exp $

DISTNAME=	rmagick-3.2.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rmagick/RMagick/}
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rmagick/rmagick
COMMENT=	Ruby binding to ImageMagick
LICENSE=	mit

USE_TOOLS+=	pkg-config

USE_GCC_RUNTIME=	yes

.include "../../lang/ruby/gem.mk"
.include "../../graphics/ImageMagick6/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
