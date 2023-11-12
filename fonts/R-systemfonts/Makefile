# $NetBSD: Makefile,v 1.6 2023/11/12 13:21:25 wiz Exp $

R_PKGNAME=	systemfonts
R_PKGVER=	1.0.4
PKGREVISION=	2
CATEGORIES=	fonts

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	System Native Font Finding
LICENSE=	mit	# + file LICENSE

TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../lang/R-cpp11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
