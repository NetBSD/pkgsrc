# $NetBSD: Makefile,v 1.8 2022/01/16 23:06:31 wiz Exp $

DISTNAME=	pip-audit-1.1.2
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

DEPENDS+=	${PYPKGPREFIX}-cachecontrol>=0.12.10:../../devel/py-cachecontrol
DEPENDS+=	${PYPKGPREFIX}-cyclonedx-python-lib>=0.11.1:../../security/py-cyclonedx-python-lib
DEPENDS+=	${PYPKGPREFIX}-html5lib>=1.1:../../textproc/py-html5lib
DEPENDS+=	${PYPKGPREFIX}-lockfile>=0.12.2:../../devel/py-lockfile
DEPENDS+=	${PYPKGPREFIX}-packaging>=21.0.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pip-api>=0.0.25:../../devel/py-pip-api
DEPENDS+=	${PYPKGPREFIX}-progress>=1.6:../../devel/py-progress
DEPENDS+=	${PYPKGPREFIX}-resolvelib>=0.8.0:../../devel/py-resolvelib
TEST_DEPENDS+=	${PYPKGPREFIX}-pretend-[0-9]*:../../devel/py-pretend
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_PKG_RESOURCES=	yes

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
        ${MV} pip-audit pip-audit-${PYVERSSUFFIX} || ${TRUE}
	${RM} -r ${DESTDIR}${PREFIX}/${PYSITELIB}/test

# as of 1.1.1
# 1 failed, 63 passed
TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib:${WRKSRC}/build/lib/test
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
