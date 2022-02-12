# $NetBSD: Makefile,v 1.139 2022/02/12 15:29:23 taca Exp $

DISTNAME=	rmagick-4.2.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rmagick/RMagick/}
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rmagick/rmagick
COMMENT=	Ruby binding to ImageMagick
LICENSE=	mit

USE_TOOLS+=	pkg-config

USE_GCC_RUNTIME=	yes

.include "../../lang/ruby/gem.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
