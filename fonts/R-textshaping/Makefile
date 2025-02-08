# $NetBSD: Makefile,v 1.4 2025/02/08 08:12:35 mef Exp $

R_PKGNAME=	textshaping
R_PKGVER=	1.0.0
CATEGORIES=	fonts

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Bindings to the 'HarfBuzz' and 'Fribidi' Libraries for Text Shaping
LICENSE=	mit	# + file LICENSE

DEPENDS+=	R-stringi-[0-9]*:../../textproc/R-stringi

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../fonts/R-systemfonts/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../lang/R-cpp11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
