# $NetBSD: Makefile,v 1.17 2020/05/12 08:11:36 adam Exp $

DISTNAME=	numba-0.49.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/numba/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://numba.pydata.org/
COMMENT=	NumPy aware dynamic Python compiler using LLVM
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-llvmlite>=0.31.0:../../devel/py-llvmlite
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
.for cmd in numba pycc
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${cmd} ${cmd}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
