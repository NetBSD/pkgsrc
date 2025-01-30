# $NetBSD: Makefile,v 1.8 2025/01/30 13:47:41 adam Exp $

DISTNAME=	hmmlearn-0.3.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	math python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hmmlearn/}

MAINTAINER=	matthewd@fastmail.us
HOMEPAGE=	https://github.com/hmmlearn/hmmlearn
COMMENT=	Algorithms for inference of Hidden Markov Models
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=62:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=6.2:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-scikit-learn>=0.16:../../math/py-scikit-learn
DEPENDS+=	${PYPKGPREFIX}-scipy>=0.19:../../math/py-scipy
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=5.4.1:../../devel/py-test

USE_LANGUAGES=	c c++

PYTHON_VERSIONS_INCOMPATIBLE=	39

# hmmlearn-0.3.2: Some tests still fail
do-test:
	# setup.py builds directly to prefix by default, so we need to build
	# again within the project for pytest to work
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} setup.py develop
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} --capture=no

.include "../../devel/py-pybind11/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
