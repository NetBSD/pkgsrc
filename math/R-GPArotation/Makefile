# $NetBSD: Makefile,v 1.1 2024/11/12 13:10:50 mef Exp $

R_PKGNAME=	GPArotation
R_PKGVER=	2024.3-1

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Gradient Projection Factor Rotation
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-geometry-[0-9]*:../../print/tex-geometry
TEST_DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-natbib-[0-9]*:../../print/tex-natbib
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
