# $NetBSD: Makefile,v 1.1 2019/07/31 13:28:23 brook Exp $

CATEGORIES=	math R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/sandwich/
COMMENT=	Robust covariance matrix estimators
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	sandwich
R_PKGVER=	2.5-1

DEPENDS+=	R-zoo>=1.8.6:../../math/R-zoo

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
