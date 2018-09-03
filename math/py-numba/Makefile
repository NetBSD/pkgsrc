# $NetBSD: Makefile,v 1.3 2018/09/03 23:47:44 minskim Exp $

DISTNAME=	numba-0.39.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=n/numba/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://numba.pydata.org/
COMMENT=	NumPy aware dynamic Python compiler using LLVM
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-llvmlite>=0.24.0:../../devel/py-llvmlite

USE_LANGUAGES=	c c++

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-enum34-[0-9]*:../../devel/py-enum34
DEPENDS+=	${PYPKGPREFIX}-funcsigs-[0-9]*:../../devel/py-funcsigs
DEPENDS+=	${PYPKGPREFIX}-singledispatch-[0-9]*:../../devel/py-singledispatch
.endif

.include "../../math/py-numpy/buildlink3.mk"
.include "../../lang/python/egg.mk"

post-install:
.for cmd in numba pycc
	${MV} ${DESTDIR}${PREFIX}/bin/${cmd} \
		${DESTDIR}${PREFIX}/bin/${cmd}${PYVERSSUFFIX}
.endfor

.include "../../mk/bsd.pkg.mk"
