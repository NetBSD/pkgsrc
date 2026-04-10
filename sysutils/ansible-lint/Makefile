# $NetBSD: Makefile,v 1.84 2026/04/10 07:48:56 adam Exp $

DISTNAME=	ansible_lint-26.4.0
PKGNAME=	${DISTNAME:S/_/-/}
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/ansible-lint/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ansible-lint.readthedocs.io/
COMMENT=	Checks playbooks for practices and behaviour that could be improved
LICENSE=	gnu-gpl-v3 AND mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=7.0.5:../../devel/py-setuptools_scm
DEPENDS+=	ansible-core>=2.16.14:../../sysutils/ansible-core
DEPENDS+=	${PYPKGPREFIX}-ansible-compat>=26.3.0:../../sysutils/py-ansible-compat
DEPENDS+=	${PYPKGPREFIX}-black>=24.3.0:../../textproc/py-black
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.15.1:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-distro>=1.9.0:../../devel/py-distro
DEPENDS+=	${PYPKGPREFIX}-filelock>=3.8.2:../../devel/py-filelock
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=4.10.0:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-packaging>=22.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pathspec>=1.0.3:../../devel/py-pathspec
DEPENDS+=	${PYPKGPREFIX}-referencing>=0.36.2:../../textproc/py-referencing
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml>=0.18.11:../../devel/py-ruamel-yaml
DEPENDS+=	${PYPKGPREFIX}-subprocess-tee>=0.4.1:../../sysutils/py-subprocess-tee
DEPENDS+=	${PYPKGPREFIX}-wcmatch>=8.5.0:../../textproc/py-wcmatch
DEPENDS+=	${PYPKGPREFIX}-yaml>=6.0.1:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-yamllint>=1.38.0:../../textproc/py-yamllint
TEST_DEPENDS+=	${PYPKGPREFIX}-jmespath-[0-9]*:../../textproc/py-jmespath
TEST_DEPENDS+=	${PYPKGPREFIX}-mypy-[0-9]*:../../lang/py-mypy
TEST_DEPENDS+=	${PYPKGPREFIX}-netaddr-[0-9]*:../../net/py-netaddr
TEST_DEPENDS+=	${PYPKGPREFIX}-psutil-[0-9]*:../../sysutils/py-psutil
TEST_DEPENDS+=	${PYPKGPREFIX}-pylint-[0-9]*:../../devel/py-pylint
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=2.1.0:../../devel/py-test-xdist

USE_LANGUAGES=	# none

PYTHON_VERSIONED_DEPENDENCIES=	cryptography

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
