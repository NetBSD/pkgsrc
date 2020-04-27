# $NetBSD: Makefile,v 1.123 2020/04/27 14:27:25 taca Exp $

DISTNAME=	rmagick-4.1.2
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
