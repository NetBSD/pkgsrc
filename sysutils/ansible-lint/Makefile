# $NetBSD: Makefile,v 1.1 2021/05/25 10:21:26 adam Exp $

DISTNAME=	ansible-lint-5.0.11
CATEGORIES=	sysutils python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/ansible-lint/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ansible-lint.readthedocs.io/
COMMENT=	Checks playbooks for practices and behaviour that could be improved
LICENSE=	gnu-gpl-v3 AND mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=1.15.0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-enrich>=1.2.6:../../comms/py-enrich
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-rich>=9.5.1:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-ruamel-yaml>=0.15.37:../../devel/py-ruamel-yaml
DEPENDS+=	${PYPKGPREFIX}-tenacity-[0-9]*:../../devel/py-tenacity
DEPENDS+=	${PYPKGPREFIX}-wcmatch>=7.0:../../textproc/py-wcmatch
DEPENDS+=	${PYPKGPREFIX}-yaml-[0-9]*:../../textproc/py-yaml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-rich

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} < 38
DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
