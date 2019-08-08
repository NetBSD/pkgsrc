# $NetBSD: Makefile,v 1.5 2019/08/08 19:53:49 brook Exp $

R_PKGNAME=	geoRglm
R_PKGVER=	0.9-11
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Package for generalised linear spatial models
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-geoR>=1.7.5:../../math/R-geoR
DEPENDS+=	R-sp>=1.3.1:../../math/R-sp

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
