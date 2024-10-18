# $NetBSD: Makefile,v 1.7 2024/10/18 22:54:56 mef Exp $

R_PKGNAME=	zip
R_PKGVER=	2.3.1
CATEGORIES=	archivers

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Cross-platform 'zip' compression
LICENSE=	cc0-1.0-universal

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-processx-[0-9]*:../../sysutils/R-processx
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-withr-[0-9]*:../../devel/R-withr

TEST_DEPENDS+=	tex-texlive.infra-[0-9]*:../../print/tex-texlive.infra

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
