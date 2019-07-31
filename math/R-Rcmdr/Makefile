# $NetBSD: Makefile,v 1.9 2019/07/31 18:36:27 brook Exp $

CATEGORIES=	math R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/Rcmdr/
COMMENT=	Platform-independent basic-statistics GUI for R
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	Rcmdr
R_PKGVER=	2.5-3

DEPENDS+=	R-tcltk2>=1.2.6:../../devel/R-tcltk2
DEPENDS+=	R-effects>=4.0.3:../../graphics/R-effects
DEPENDS+=	R-abind>=1.4.5:../../math/R-abind
DEPENDS+=	R-car>=3.0.1:../../math/R-car
DEPENDS+=	R-RcmdrMisc>=2.5.1:../../math/R-RcmdrMisc
DEPENDS+=	R-relimp>=1.0.5:../../math/R-relimp

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
