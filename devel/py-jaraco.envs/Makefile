# $NetBSD: Makefile,v 1.9 2025/04/12 11:33:32 adam Exp $

DISTNAME=	jaraco.envs-2.6.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jaraco.envs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/jaraco.envs
COMMENT=	Classes for orchestrating Python (virtual) environments
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=3.4.1:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-path-[0-9]*:../../devel/py-path
DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox
DEPENDS+=	${PYPKGPREFIX}-virtualenv-[0-9]*:../../devel/py-virtualenv
# TODO: import py-test-enable
# as of 2.6.0
# 3 failed, 4 passed
TEST_DEPENDS+=	${PYPKGPREFIX}-test-checkdocs>=0:../../devel/py-test-checkdocs
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-flake8-[0-9]*:../../devel/py-test-flake8

USE_LANGUAGES=	# none

WHEEL_NAME=	${DISTNAME:S/./_/}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
