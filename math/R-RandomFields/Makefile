# $NetBSD: Makefile,v 1.3 2018/07/28 14:40:46 brook Exp $

CATEGORIES=	math

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	${R_HOMEPAGE_BASE}/RandomFields/
COMMENT=	Simulation and analysis of random fields
LICENSE=	gnu-gpl-v2

R_PKGNAME=	RandomFields
R_PKGVER=	2.0.66

USE_LANGUAGES+=	c c++ fortran

.include "../../math/R/Makefile.extension"
.include "../../math/blas/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
