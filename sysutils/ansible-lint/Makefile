# $NetBSD: Makefile,v 1.23 2023/01/12 11:58:13 adam Exp $

DISTNAME=	ansible-lint-6.10.2
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/ansible-lint/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ansible-lint.readthedocs.io/
COMMENT=	Checks playbooks for practices and behaviour that could be improved
LICENSE=	gnu-gpl-v3 AND mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=7.0.0:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	ansible-core>=2.12.0:../../sysutils/ansible-core
DEPENDS+=	${PYPKGPREFIX}-ansible-compat>=2.2.7:../../sysutils/py-ansible-compat
DEPENDS+=	${PYPKGPREFIX}-black>=22.8.0:../../textproc/py-black
DEPENDS+=	${PYPKGPREFIX}-filelock>=3.3.0:../../devel/py-filelock
DEPENDS+=	${PYPKGPREFIX}-jsonschema>=4.10.0:../../textproc/py-jsonschema
DEPENDS+=	${PYPKGPREFIX}-packaging>=21.3:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-rich>=12.0.0:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml>=0.17.21:../../devel/py-ruamel-yaml
DEPENDS+=	${PYPKGPREFIX}-wcmatch>=8.1.2:../../textproc/py-wcmatch
DEPENDS+=	${PYPKGPREFIX}-yaml>=5.4.1:../../textproc/py-yaml
DEPENDS+=	${PYPKGPREFIX}-yamllint>=1.26.3:../../textproc/py-yamllint

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38 # ansible

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
