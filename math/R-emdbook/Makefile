# $NetBSD: Makefile,v 1.5 2022/12/18 11:27:33 mef Exp $

R_PKGNAME=	emdbook
R_PKGVER=	1.3.12
CATEGORIES=	math

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Support functions and data for "Ecological Models and Data"
LICENSE=	gnu-gpl-v1 OR gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-bbmle>=1.0.20:../../math/R-bbmle
DEPENDS+=	R-coda>=0.19.3:../../math/R-coda
DEPENDS+=	R-plyr>=1.8.4:../../math/R-plyr

# Packages suggested but not available: 'R2jags', 'ellipse', 'SuppDists'

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
