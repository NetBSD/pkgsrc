# $NetBSD: Makefile,v 1.3 2024/11/03 06:43:11 mef Exp $

R_PKGNAME=	hexbin
R_PKGVER=	1.28.4

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Hexagonal Binning Routines
LICENSE=	gnu-gpl-v2

# Packages suggested but not available: 'marray', 'affy', 'Biobase', 'limma'
TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
