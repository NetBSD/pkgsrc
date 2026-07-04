# $NetBSD: Makefile,v 1.12 2026/07/04 23:32:31 mef Exp $

R_PKGNAME=	later
R_PKGVER=	1.4.8
PKGREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Utilities for delaying function execution
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-rlang>=0.4.0:../../devel/R-rlang

# Package suggested but not available: 'nanonext'

TEST_DEPENDS+=	R-knitr-[0-9]*:../../print/R-knitr
TEST_DEPENDS+=	R-rmarkdown-[0-9]*:../../textproc/R-rmarkdown
TEST_DEPENDS+=	R-testthat-[0-9]*:../../devel/R-testthat

MAKE_ENV+=	-DEXTRA_PKG_LIBS=-lexecinfo
USE_LANGUAGES=	c c++

.include "../../mk/bsd.prefs.mk"
SUBST_CLASSES+=		pkglibs
SUBST_STAGE.pkglibs=	pre-configure
SUBST_FILES.pkglibs=	src/Makevars.in
SUBST_MESSAGE.pkglibs=	Add -lexecinfo for *BSD
.if ${OPSYS} != SunOS && ${OPSYS} != Linux && ${OPSYS} != Darwin
SUBST_SED.pkglibs=	-e s,@@PKG_LIBS@@,PKG_LIBS+=-lexecinfo,
.else
SUBST_SED.pkglibs=	-e s,@@PKG_LIBS@@,,
.endif


.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_PLATFORM:MNetBSD-*-i386}
.include "../../devel/libatomic/buildlink3.mk"
.endif

.include "../../math/R/Makefile.extension"
.include "../../devel/R-Rcpp/buildlink3.mk"
.include "../../devel/R-BH/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
