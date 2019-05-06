# $NetBSD: Makefile,v 1.114 2019/05/06 15:38:19 taca Exp $

DISTNAME=	rmagick-3.1.0
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
