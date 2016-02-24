# $NetBSD: Makefile,v 1.10 2016/02/24 06:41:46 wen Exp $

CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_R_CRAN:=contrib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/geoR/
COMMENT=	Geostatistical analysis including likelihood-based & Bayesian methods
LICENSE=	gnu-gpl-v2

R_PKGNAME=	geoR
R_PKGVER=	1.7-5.1

DEPENDS+=	R-RandomFields>=2.0.54:../../math/R-RandomFields
DEPENDS+=	R-sp>=0.9.98:../../math/R-sp
DEPENDS+=	R-splancs>=2.01.31:../../math/R-splancs

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
