# $NetBSD: Makefile,v 1.5 2019/08/08 19:53:45 brook Exp $

R_PKGNAME=	RandomFields
R_PKGVER=	3.3.6
CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Simulation and analysis of random fields
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-sp>=1.3.1:../../math/R-sp

USE_LANGUAGES+=	c c++ fortran

.include "../../math/R/Makefile.extension"
.include "../../math/R-RandomFieldsUtils/buildlink3.mk"
.include "../../math/blas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
