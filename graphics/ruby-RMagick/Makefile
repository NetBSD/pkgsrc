# $NetBSD: Makefile,v 1.148 2023/01/29 21:16:44 ryoon Exp $

DISTNAME=	rmagick-5.1.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/rmagick/RMagick/}
PKGREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rmagick/rmagick
COMMENT=	Ruby binding to ImageMagick
LICENSE=	mit

USE_GCC_RUNTIME=	yes

.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../lang/ruby/gem.mk"
.include "../../graphics/ImageMagick/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
