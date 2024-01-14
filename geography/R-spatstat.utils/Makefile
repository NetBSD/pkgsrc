# $NetBSD: Makefile,v 1.4 2024/01/14 03:03:26 mef Exp $

R_PKGNAME=	spatstat.utils
R_PKGVER=	3.0-4
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Utility Functions for 'spatstat'
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

TEST_DEPENDS+=	R-spatstat.model-[0-9]*:../../geography/R-spatstat.model
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
