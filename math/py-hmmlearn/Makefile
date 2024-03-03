# $NetBSD: Makefile,v 1.4 2024/03/03 14:03:28 bacon Exp $

DISTNAME=	hmmlearn-0.3.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hmmlearn/}

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/hmmlearn/hmmlearn
COMMENT=	Algorithms for inference of Hidden Markov Models
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-scikit-learn>=0.16:../../math/py-scikit-learn
DEPENDS+=	${PYPKGPREFIX}-matplotlib>0:../../graphics/py-matplotlib
DEPENDS+=	${PYPKGPREFIX}-scipy>0.19:../../math/py-scipy
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=5.4.1:../../devel/py-test

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

# hmmlearn-0.3.2: Some tests still fail
do-test:
	# setup.py builds directly to prefix by default, so we need to build
	# again within the project for pytest to work
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} setup.py develop
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} --capture=no

.include "../../lang/python/wheel.mk"
.include "../../devel/py-pybind11/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
