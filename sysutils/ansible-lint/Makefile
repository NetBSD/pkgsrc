# $NetBSD: Makefile,v 1.55 2024/06/08 07:47:05 adam Exp $

DISTNAME=	ansible_lint-24.6.0
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/ansible-lint/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ansible-lint.readthedocs.io/
COMMENT=	Checks playbooks for practices and behaviour that could be improved
LICENSE=	gnu-gpl-v3 AND mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=65.3.0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=7.0.5:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	ansible-core>=2.13.0:../../sysutils/ansible-core
DEPENDS+=	${PYPKGPREFIX}-ansible-compat>=24.5.0:../../sysutils/py-ansible-compat
DEPENDS+=	${PYPKGPREFIX}-black>=24.3.0:../../textproc/py-black
DEPENDS+=	${PYPKGPREFIX}-filelock>=3.3.0:../../devel/py-filelock
DEPENDS+=	${PYPKGPREFIX}-importlib-metadata-[0-9]*:../../devel/py-importlib-metadata
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=4.10.0:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-packaging>=21.3:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pathspec>=0.10.3:../../devel/py-pathspec
DEPENDS+=	${PYPKGPREFIX}-rich>=12.0.0:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml>=0.18.5:../../devel/py-ruamel-yaml
DEPENDS+=	${PYPKGPREFIX}-subprocess-tee>=0.4.1:../../sysutils/py-subprocess-tee
DEPENDS+=	${PYPKGPREFIX}-wcmatch>=8.5.0:../../textproc/py-wcmatch
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.4.1:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-yamllint>=1.30.0:../../textproc/py-yamllint
TEST_DEPENDS+=	${PYPKGPREFIX}-jmespath-[0-9]*:../../textproc/py-jmespath
TEST_DEPENDS+=	${PYPKGPREFIX}-mypy-[0-9]*:../../lang/py-mypy
TEST_DEPENDS+=	${PYPKGPREFIX}-netaddr-[0-9]*:../../net/py-netaddr
TEST_DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil
TEST_DEPENDS+=	${PYPKGPREFIX}-pylint-[0-9]*:../../devel/py-pylint
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=2.1.0:../../devel/py-test-xdist

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38 39

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
