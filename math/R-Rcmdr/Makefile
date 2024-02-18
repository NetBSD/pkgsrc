# $NetBSD: Makefile,v 1.15 2024/02/18 14:44:31 mef Exp $

R_PKGNAME=	Rcmdr
R_PKGVER=	2.9-2

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Platform-independent basic-statistics GUI for R
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-tcltk2>=1.2.6:../../devel/R-tcltk2
DEPENDS+=	R-effects>=4.0.3:../../graphics/R-effects
DEPENDS+=	R-RcmdrMisc>=2.7.1:../../math/R-RcmdrMisc
DEPENDS+=	R-abind>=1.4.5:../../math/R-abind
DEPENDS+=	R-car>=3.0.8:../../math/R-car
DEPENDS+=	R-relimp>=1.0.5:../../math/R-relimp

# Packages suggested but not available:
#   'leaps', 'multcomp', 'sem'
TEST_DEPENDS+=	R-aplpack-[0-9]*:../../math/R-aplpack
TEST_DEPENDS+=	R-lmtest-[0-9]*:../../math/R-lmtest
TEST_DEPENDS+=	R-rgl-[0-9]*:../../graphics/R-rgl

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
