# $NetBSD: Makefile,v 1.6 2025/02/08 09:00:50 mef Exp $

R_PKGNAME=	spatstat.utils
R_PKGVER=	3.1-2
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Utility Functions for 'spatstat'
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

TEST_DEPENDS+=	R-spatstat.model-[0-9]*:../../geography/R-spatstat.model

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
