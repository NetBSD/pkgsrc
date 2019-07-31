# $NetBSD: Makefile,v 1.7 2019/07/31 18:21:25 brook Exp $

CATEGORIES=	math R

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/RArcInfo/
COMMENT=	Functions to import data from Arc/Info V7.x binary coverages
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

R_PKGNAME=	RArcInfo
R_PKGVER=	0.4-12

DEPENDS+=	R-RColorBrewer>=1.0.5:../../math/R-RColorBrewer

USE_LANGUAGES=	c

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
