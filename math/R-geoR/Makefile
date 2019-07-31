# $NetBSD: Makefile,v 1.12 2019/07/31 19:32:49 brook Exp $

CATEGORIES=	math R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/geoR/
COMMENT=	Analysis of geostatistical data
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	geoR
R_PKGVER=	1.7-5.2.1

DEPENDS+=	R-RandomFields>=2.0.54:../../math/R-RandomFields
DEPENDS+=	R-sp>=1.3.1:../../math/R-sp
DEPENDS+=	R-splancs>=2.01.39:../../math/R-splancs

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
