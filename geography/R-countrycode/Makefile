# $NetBSD: Makefile,v 1.9 2024/11/26 13:02:05 mef Exp $

R_PKGNAME=	countrycode
R_PKGVER=	1.6.0
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Convert country names and country codes
LICENSE=	gnu-gpl-v3

# Packages suggested but not available: 'altdoc', 'eurostat', 'ISOcodes'
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-tibble-[0-9]*:../../math/R-tibble
TEST_DEPENDS+=	R-utf8-[0-9]*:../../textproc/R-utf8

TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
