# $NetBSD: Makefile,v 1.19 2023/06/17 12:03:36 mef Exp $

R_PKGNAME=	gdata
R_PKGVER=	2.19.0

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Various R programming tools for data manipulation
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-gtools>=3.5.0:../../math/R-gtools
DEPENDS+=	R-RUnit-[0-9]*:../../devel/R-RUnit

TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-ae-[0-9]*:../../fonts/tex-ae
TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-epstopdf-pkg-[0-9]*:../../print/tex-epstopdf-pkg
TEST_DEPENDS+=	tex-fancyhdr-[0-9]*:../../print/tex-fancyhdr
TEST_DEPENDS+=	tex-hyperref-[0-9]*:../../print/tex-hyperref
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-natbib-[0-9]*:../../print/tex-natbib
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_TOOLS+=	perl:run
REPLACE_PERL+=	inst/bin/*.bat inst/perl/*.pl
USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
