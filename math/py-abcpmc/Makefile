# $NetBSD: Makefile,v 1.3 2016/10/12 19:51:45 kamil Exp $

DISTNAME=	abcpmc-0.1.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/abcpmc/}

MAINTAINER=	jihbed.research@gmail.com
HOMEPAGE=	http://www.cosmology.ethz.ch/research/software-lab/abcpmc.html
COMMENT=	Approximate Bayesian Computation Population Monte Carlo
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	# none

# TEST_DEPENDS
.include "../../lang/python/pyversion.mk"

.if ${_PYTHON_VERSION} < 33
BUILD_DEPENDS+=	${PYPKGPREFIX}-funcsigs-[0-9]*:../../devel/py-funcsigs
.endif
BUILD_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
BUILD_DEPENDS+=	${PYPKGPREFIX}-pbr-[0-9]*:../../devel/py-pbr
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-scipy-[0-9]*:../../math/py-scipy

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
