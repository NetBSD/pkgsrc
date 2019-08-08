# $NetBSD: Makefile,v 1.13 2019/08/08 19:53:49 brook Exp $

R_PKGNAME=	geoR
R_PKGVER=	1.7-5.2.1
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Analysis of geostatistical data
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-RandomFields>=2.0.54:../../math/R-RandomFields
DEPENDS+=	R-sp>=1.3.1:../../math/R-sp
DEPENDS+=	R-splancs>=2.01.39:../../math/R-splancs

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
