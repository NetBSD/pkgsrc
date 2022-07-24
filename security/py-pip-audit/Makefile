# $NetBSD: Makefile,v 1.17 2022/07/24 11:09:03 wiz Exp $

DISTNAME=	pip-audit-2.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
# pypi file does not include tests
#MASTER_SITES=	${MASTER_SITE_PYPI:=p/pip-audit/}
MASTER_SITES=	${MASTER_SITE_GITHUB:=trailofbits/}
GITHUB_PROJECT=	pip-audit
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/pip-audit/
COMMENT=	Scan Python environments for known vulnerabilities
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-flit_core-[0-9]*:../../devel/py-flit_core
# unlisted but used
DEPENDS+=	${PYPKGPREFIX}-cachecontrol>=0.12.10:../../devel/py-cachecontrol
DEPENDS+=	${PYPKGPREFIX}-cyclonedx-python-lib>=2.0.0:../../security/py-cyclonedx-python-lib
DEPENDS+=	${PYPKGPREFIX}-html5lib>=1.1:../../textproc/py-html5lib
DEPENDS+=	${PYPKGPREFIX}-packaging>=21.0.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pip-api>=0.0.28:../../devel/py-pip-api
DEPENDS+=	${PYPKGPREFIX}-pip-requirements-parser>=31.2.0:../../devel/py-pip-requirements-parser
DEPENDS+=	${PYPKGPREFIX}-resolvelib>=0.8.0:../../devel/py-resolvelib
DEPENDS+=	${PYPKGPREFIX}-rich>=12.4:../../comms/py-rich
DEPENDS+=	${PYPKGPREFIX}-toml>=0.10:../../textproc/py-toml
TEST_DEPENDS+=	${PYPKGPREFIX}-pretend-[0-9]*:../../devel/py-pretend
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
        ${MV} pip-audit pip-audit-${PYVERSSUFFIX} || ${TRUE}

# as of 2.4.2
# 1 failed, 166 passed
TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib:${WRKSRC}/build/lib/test
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
