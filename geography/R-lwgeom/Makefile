# $NetBSD: Makefile,v 1.15 2023/11/08 13:19:23 wiz Exp $

R_PKGNAME=	lwgeom
R_PKGVER=	0.2-8
PKGREVISION=	7
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Bindings to Selected 'liblwgeom' Functions for Simple Features
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-units>=0.6.5:../../math/R-units

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-geosphere-[0-9]*:../../geography/R-geosphere
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-wk-[0-9]*:../../geography/R-wk

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../geography/R-sf/buildlink3.mk"
.include "../../geography/geos/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
