# $NetBSD: Makefile,v 1.11 2022/09/19 08:27:34 adam Exp $

DISTNAME=	ansible-lint-6.6.0
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/ansible-lint/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ansible-lint.readthedocs.io/
COMMENT=	Checks playbooks for practices and behaviour that could be improved
LICENSE=	gnu-gpl-v3 AND mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=1.15.0:../../devel/py-setuptools_scm
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm_git_archive>=1.0:../../devel/py-setuptools_scm_git_archive
BUILD_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	ansible-core>=2.12.0:../../sysutils/ansible-core
DEPENDS+=	${PYPKGPREFIX}-ansible-compat>=2.2.0:../../sysutils/py-ansible-compat
DEPENDS+=	${PYPKGPREFIX}-black>=22.1.0:../../textproc/py-black
DEPENDS+=	${PYPKGPREFIX}-enrich>=1.2.6:../../comms/py-enrich
DEPENDS+=	${PYPKGPREFIX}-filelock-[0-9]*:../../devel/py-filelock
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=4.9.0:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-rich>=9.5.1:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml>=0.15.37:../../devel/py-ruamel-yaml
DEPENDS+=	${PYPKGPREFIX}-wcmatch>=7.0:../../textproc/py-wcmatch
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-yamllint>=1.25.0:../../textproc/py-yamllint

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 38
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions
.endif

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
