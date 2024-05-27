# $NetBSD: Makefile,v 1.23 2024/05/27 11:18:25 adam Exp $

DISTNAME=	ansible_compat-24.5.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/ansible-compat/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ansible-community/ansible-compat
COMMENT=	Ansible compatibility goodies
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=65.3.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=7.0.5:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	ansible-core>=2.12:../../sysutils/ansible-core
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=4.6.0:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-subprocess-tee>=0.4.1:../../sysutils/py-subprocess-tee
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
#TODO: TEST_DEPENDS pip-tools, pytest-plus
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-flaky-[0-9]*:../../devel/py-flaky
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 310
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.5.0:../../devel/py-typing-extensions
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
