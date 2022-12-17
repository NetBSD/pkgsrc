# $NetBSD: Makefile,v 1.1 2022/12/17 14:35:09 mef Exp $

R_PKGNAME=	textshaping
R_PKGVER=	0.3.6
CATEGORIES=	fonts

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Bindings to the 'HarfBuzz' and 'Fribidi' Libraries for Text Shaping
LICENSE=	mit	# + file LICENSE

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../fonts/R-systemfonts/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../lang/R-cpp11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
