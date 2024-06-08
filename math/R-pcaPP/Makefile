# $NetBSD: Makefile,v 1.1 2024/06/08 15:18:36 mef Exp $

R_PKGNAME=	pcaPP
R_PKGVER=	2.0-4

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Robust PCA by Projection Pursuit
LICENSE=	gnu-gpl-v3

DEPENDS+=	R-mvtnorm>=1.2.5:../../math/R-mvtnorm

USE_LANGUAGES=	c c++ fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/bsd.pkg.mk"
