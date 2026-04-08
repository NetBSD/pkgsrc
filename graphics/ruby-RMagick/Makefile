# $NetBSD: Makefile,v 1.196 2026/04/08 14:54:20 taca Exp $

DISTNAME=	rmagick-6.2.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rmagick/RMagick/}
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rmagick/rmagick
COMMENT=	Ruby binding to ImageMagick
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-pkg-config>=1.4<2:../../devel/ruby-pkg-config

USE_GCC_RUNTIME=	yes
USE_LANGUAGES=		c c++
FORCE_C_STD=		c99

BUILDLINK_TRANSFORM.Darwin+=	rm:-Wl,--no-as-needed

.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../lang/ruby/gem.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
