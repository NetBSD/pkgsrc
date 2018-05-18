# $NetBSD: Makefile,v 1.1 2018/05/18 16:08:49 minskim Exp $

DISTNAME=	numba-0.37.0
GITHUB_PROJECT=	numba
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=numba/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://numba.pydata.org/
COMMENT=	NumPy aware dynamic Python compiler using LLVM
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-llvmlite>=0.22:../../devel/py-llvmlite

USE_LANGUAGES=	c c++

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
