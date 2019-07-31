# $NetBSD: Makefile,v 1.1 2019/07/31 13:21:43 brook Exp $

CATEGORIES=	math R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/mitools/
COMMENT=	Tools for multiple imputation of missing data
LICENSE=	gnu-gpl-v2

R_PKGNAME=	mitools
R_PKGVER=	2.4

DEPENDS+=	R-DBI>=1.0.0:../../math/R-DBI

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
