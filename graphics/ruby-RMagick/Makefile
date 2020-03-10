# $NetBSD: Makefile,v 1.121 2020/03/10 22:10:13 wiz Exp $

DISTNAME=	rmagick-4.0.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rmagick/RMagick/}
PKGREVISION=	2
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
