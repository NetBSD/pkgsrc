# $NetBSD: Makefile,v 1.168 2024/05/05 17:02:30 taca Exp $

DISTNAME=	rmagick-6.0.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rmagick/RMagick/}
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rmagick/rmagick
COMMENT=	Ruby binding to ImageMagick
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-pkg-config>=1.4<2:../../devel/ruby-pkg-config
DEPENDS+=	${RUBY_PKGPREFIX}-observer>=0.1<1:../../devel/ruby-observer

USE_GCC_RUNTIME=	yes
USE_LANGUAGES=		c c++
FORCE_C_STD=		c99

BUILDLINK_TRANSFORM.Darwin+=	rm:-Wl,--no-as-needed

.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../lang/ruby/gem.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
