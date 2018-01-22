# $NetBSD: Makefile,v 1.4 2018/01/22 07:41:38 wen Exp $
#

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/car/
COMMENT=	Accompanies An R Companion to Applied Regression, 2nd Edition
LICENSE=	gnu-gpl-v2

R_PKGNAME=	car
R_PKGVER=	2.1-6

WRKSRC=		${WRKDIR}/car
USE_LANGUAGES=	# none

DEPENDS+=	R-quantreg>=0:../../math/R-quantreg \
		R-pbkrtest>=0.4.4:../../math/R-pbkrtest

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
