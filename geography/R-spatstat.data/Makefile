# $NetBSD: Makefile,v 1.1 2020/08/07 03:44:39 brook Exp $

R_PKGNAME=	spatstat.data
R_PKGVER=	1.4-3
CATEGORIES=	geography

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Datasets for 'spatstat'
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-spatstat.utils>=1.17.0:../../geography/R-spatstat.utils

USE_LANGUAGES=	# none

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
