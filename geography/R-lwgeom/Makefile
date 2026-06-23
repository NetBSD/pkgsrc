# $NetBSD: Makefile,v 1.32 2026/06/23 15:06:47 mef Exp $

R_PKGNAME=	lwgeom
R_PKGVER=	0.2-14
PKGREVISION=	8
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Bindings to Selected 'liblwgeom' Functions for Simple Features
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-units>=0.6.5:../../math/R-units

TEST_DEPENDS+=	R-covr-[0-9]*:../../devel/R-covr
TEST_DEPENDS+=	R-geosphere-[0-9]*:../../geography/R-geosphere
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat
TEST_DEPENDS+=	R-wk-[0-9]*:../../geography/R-wk

TEST_DEPENDS+=	tex-ec-[0-9]*:../../fonts/tex-ec
TEST_DEPENDS+=	tex-inconsolata-[0-9]*:../../fonts/tex-inconsolata
TEST_DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
TEST_DEPENDS+=	tex-url-[0-9]*:../../print/tex-url
TEST_DEPENDS+=	tex-xkeyval-[0-9]*:../../print/tex-xkeyval

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

.include "../../mk/bsd.prefs.mk"
SUBST_CLASSES+=         pkglibs
SUBST_STAGE.pkglibs=	pre-configure
SUBST_FILES.pkglibs=	src/Makevars.in
SUBST_MESSAGE.pkglibs=	Add -lexecinfo for *BSD
.if ${OPSYS} != SunOS && ${OPSYS} != Linux
SUBST_SED.pkglibs=	-e s,@@PKG_LIBS@@,PKG_LIBS+=-lexecinfo,
.else
SUBST_SED.pkglibs=	-e s,@@PKG_LIBS@@,,
.endif

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../geography/R-sf/buildlink3.mk"
.include "../../geography/geos/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
