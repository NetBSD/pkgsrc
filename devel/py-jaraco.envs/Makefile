# $NetBSD: Makefile,v 1.6 2023/10/28 19:57:02 wiz Exp $

DISTNAME=	jaraco.envs-2.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jaraco.envs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/jaraco.envs
COMMENT=	Classes for orchestrating Python (virtual) environments
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4.1:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-path-[0-9]*:../../devel/py-path
DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox
DEPENDS+=	${PYPKGPREFIX}-virtualenv-[0-9]*:../../devel/py-virtualenv
# TODO: import py-test-checkdocs, py-test-enable
#TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6:../../devel/py-test
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8-[0-9]*:../../devel/py-test-flake8

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

#TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib
#
#do-test:
#	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
