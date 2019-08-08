# $NetBSD: Makefile,v 1.2 2019/08/08 19:53:53 brook Exp $

R_PKGNAME=	sandwich
R_PKGVER=	2.5-1
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Robust covariance matrix estimators
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-zoo>=1.8.6:../../math/R-zoo

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
