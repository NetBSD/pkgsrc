# $NetBSD: Makefile,v 1.5 2022/08/02 09:51:23 adam Exp $

DISTNAME=	ansible-compat-2.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/ansible-compat/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ansible-community/ansible-compat
COMMENT=	Ansible compatibility goodies
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
BUILD_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=4.6.0:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-subprocess-tee>=0.3.5:../../sysutils/py-subprocess-tee
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
#TODO: TEST_DEPENDS pip-tools, pytest-markdown, pytest-plus
TEST_DEPENDS+=	ansible-core-[0-9]*:../../sysutils/ansible-core
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky-[0-9]*:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 37

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} test

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
