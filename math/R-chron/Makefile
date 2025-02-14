# $NetBSD: Makefile,v 1.15 2025/02/14 14:06:09 mef Exp $

R_PKGNAME=	chron
R_PKGVER=	2.3-62

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Chronological objects which can handle dates and times
LICENSE=	gnu-gpl-v2

TEST_DEPENDS+=	R-scales-[0-9]*:../../graphics/R-scales
TEST_DEPENDS+=	R-ggplot2-[0-9]*:../../graphics/R-ggplot2

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
