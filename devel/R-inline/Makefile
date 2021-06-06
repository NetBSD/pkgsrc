# $NetBSD: Makefile,v 1.5 2021/06/06 12:53:18 mef Exp $

R_PKGNAME=	inline
R_PKGVER=	0.3.19
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
COMMENT=	Functions to inline C, C++, Fortran function calls from R
LICENSE=	gnu-lgpl-v2 OR gnu-lgpl-v2.1 OR gnu-lgpl-v3

# test only (?)
USE_LANGUAGES=	c c++ fortran

.include "../../math/R/Makefile.extension"
.include "../../mk/compiler/gfortran.mk"
.include "../../mk/bsd.pkg.mk"
