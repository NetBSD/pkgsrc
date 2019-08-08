# $NetBSD: Makefile,v 1.2 2019/08/08 19:53:51 brook Exp $

R_PKGNAME=	mitools
R_PKGVER=	2.4
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Tools for multiple imputation of missing data
LICENSE=	gnu-gpl-v2

DEPENDS+=	R-DBI>=1.0.0:../../math/R-DBI

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
