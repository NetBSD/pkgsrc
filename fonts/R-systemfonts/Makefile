# $NetBSD: Makefile,v 1.3 2023/01/29 21:16:04 ryoon Exp $

R_PKGNAME=	systemfonts
R_PKGVER=	1.0.4
PKGREVISION=	1
CATEGORIES=	fonts

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	System Native Font Finding
LICENSE=	mit	# + file LICENSE

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../lang/R-cpp11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
