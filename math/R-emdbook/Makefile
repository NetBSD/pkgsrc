# $NetBSD: Makefile,v 1.1 2018/03/05 16:57:36 minskim Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.math.mcmaster.ca/bolker/emdbook/
COMMENT=	Support functions and data for "Ecological Models and Data"
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-bbmle-[0-9]*:../../math/R-bbmle
DEPENDS+=	R-coda-[0-9]*:../../math/R-coda
DEPENDS+=	R-plyr-[0-9]*:../../math/R-plyr

R_PKGNAME=	emdbook
R_PKGVER=	1.3.9

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
