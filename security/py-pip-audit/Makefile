# $NetBSD: Makefile,v 1.34 2024/02/14 21:36:32 adam Exp $

DISTNAME=	pip_audit-2.7.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pip-audit/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/pip-audit
COMMENT=	Scan Python environments for known vulnerabilities
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.2:../../devel/py-flit_core
DEPENDS+=	${PYPKGPREFIX}-cachecontrol>=0.13.0:../../devel/py-cachecontrol
DEPENDS+=	${PYPKGPREFIX}-cyclonedx-python-lib>=5:../../security/py-cyclonedx-python-lib
DEPENDS+=	${PYPKGPREFIX}-html5lib>=1.1:../../textproc/py-html5lib
DEPENDS+=	${PYPKGPREFIX}-packaging>=23.0.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pip-api>=0.0.28:../../devel/py-pip-api
DEPENDS+=	${PYPKGPREFIX}-pip-requirements-parser>=32.0.0:../../devel/py-pip-requirements-parser
DEPENDS+=	${PYPKGPREFIX}-requests>=2.31.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-rich>=12.4:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-toml>=0.10:../../textproc/py-toml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 38

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
        ${MV} pip-audit pip-audit-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
