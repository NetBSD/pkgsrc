# $NetBSD: Makefile,v 1.6 2026/07/09 13:16:15 mef Exp $

R_PKGNAME=	readxl
R_PKGVER=	1.5.0
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Read Excel files
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-tibble>=1.3.1:../../math/R-tibble
DEPENDS+=	R-cellranger>=1.1.0:../../textproc/R-cellranger

USE_LANGUAGES+=	c c++

.include "../../mk/bsd.prefs.mk"

SUBST_CLASSES+=		pkglibs
SUBST_STAGE.pkglibs=	pre-configure
SUBST_FILES.pkglibs=	src/Makevars
SUBST_MESSAGE.pkglibs=	Add -lexecinfo for *BSD
.if ${OPSYS} != SunOS && ${OPSYS} != Linux && ${OPSYS} != Darwin
SUBST_SED.pkglibs=	-e s,@@PKG_LIBS@@,PKG_LIBS+=-lexecinfo,
.else
SUBST_SED.pkglibs=	-e s,@@PKG_LIBS@@,,
.endif

.include "../../math/R/Makefile.extension"
.include "../../lang/R-cpp11/buildlink3.mk"
.include "../../sysutils/R-progress/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
