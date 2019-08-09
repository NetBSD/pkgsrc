# $NetBSD: Makefile,v 1.1 2019/08/09 15:48:20 brook Exp $

R_PKGNAME=	robustbase
R_PKGVER=	0.93-5
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Basic robust statistics
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	R-DEoptimR>=1.0.8:../../math/R-DEoptimR

USE_LANGUAGES=	c fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"

