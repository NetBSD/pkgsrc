# $NetBSD: Makefile,v 1.32 2023/07/01 08:37:39 wiz Exp $

DISTNAME=	numba-0.55.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/numba/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://numba.pydata.org/
COMMENT=	NumPy aware dynamic Python compiler using LLVM
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-llvmlite>=0.38.0:../../devel/py-llvmlite
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

# OpenMP is not portable
MAKE_ENV+=	NUMBA_DISABLE_OPENMP=1

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	27 37 38

USE_PKG_RESOURCES=	yes

post-install:
.for cmd in numba pycc
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${cmd} ${cmd}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
