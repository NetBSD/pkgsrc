# $NetBSD: Makefile,v 1.1 2021/11/16 16:04:40 wiz Exp $

DISTNAME=	pip-audit-0.0.5
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

DEPENDS+=	${PYPKGPREFIX}-cachecontrol>=0.12.6:../../devel/py-cachecontrol
DEPENDS+=	${PYPKGPREFIX}-html5lib>=1.1:../../textproc/py-html5lib
DEPENDS+=	${PYPKGPREFIX}-lockfile>=0.12.2:../../devel/py-lockfile
DEPENDS+=	${PYPKGPREFIX}-packaging>=21.0.0:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-pip-api>=0.0.23:../../devel/py-pip-api
DEPENDS+=	${PYPKGPREFIX}-progress>=1.6:../../devel/py-progress
DEPENDS+=	${PYPKGPREFIX}-resolvelib>=0.8.0:../../devel/py-resolvelib
TEST_DEPENDS+=	${PYPKGPREFIX}-pretend-[0-9]*:../../devel/py-pretend
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"

.if ${_PYTHON_VERSION} == 36
DEPENDS+=	${PYPKGPREFIX}-dataclasses>=0.6:../../devel/py-dataclasses
.endif

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
        ${MV} pip-audit pip-audit-${PYVERSSUFFIX} || ${TRUE}
	${RM} -r ${DESTDIR}${PREFIX}/${PYSITELIB}/test

# as of 0.0.4
# 2 failed, 46 passed
# https://github.com/trailofbits/pip-audit/issues/115
TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib:${WRKSRC}/build/lib/test
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
