# $NetBSD: Makefile,v 1.3 2019/07/31 19:23:25 brook Exp $

CATEGORIES=	math R

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.math.mcmaster.ca/bolker/emdbook/
COMMENT=	Support functions and data for "Ecological Models and Data"
LICENSE=	gnu-gpl-v1 OR gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	emdbook
R_PKGVER=	1.3.11

DEPENDS+=	R-bbmle>=1.0.20:../../math/R-bbmle
DEPENDS+=	R-coda>=0.19.3:../../math/R-coda
DEPENDS+=	R-plyr>=1.8.4:../../math/R-plyr

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
