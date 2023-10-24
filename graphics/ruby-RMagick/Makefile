# $NetBSD: Makefile,v 1.158 2023/10/24 22:09:31 wiz Exp $

DISTNAME=	rmagick-5.3.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rmagick/RMagick/}
PKGREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rmagick/rmagick
COMMENT=	Ruby binding to ImageMagick
LICENSE=	mit

USE_GCC_RUNTIME=	yes

BUILDLINK_TRANSFORM.Darwin+=	rm:-Wl,--no-as-needed

.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../lang/ruby/gem.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
