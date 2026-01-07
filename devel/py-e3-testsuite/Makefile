# $NetBSD: Makefile,v 1.5 2026/01/07 08:07:26 wiz Exp $

DISTNAME=	e3_testsuite-27.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/e3_testsuite/}

MAINTAINER=	dkazankov@NetBSD.org
HOMEPAGE=	https://github.com/AdaCore/e3-testsuite
COMMENT=	E3 testsuite - generic testsuite framework in Python
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=61:../../devel/py-setuptools

DEPENDS+=	${PYPKGPREFIX}-e3-core-[0-9]*:../../devel/py-e3-core

DEPENDS+=	${PYPKGPREFIX}-mypy-[0-9]*:../../lang/py-mypy
DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
DEPENDS+=	${PYPKGPREFIX}-botocore-[0-9]*:../../net/py-botocore
DEPENDS+=	${PYPKGPREFIX}-boto3-[0-9]*:../../net/py-boto3
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-tqdm-[0-9]*:../../misc/py-tqdm
   
PYTHON_VERSIONS_INCOMPATIBLE=	310 311 # py-sphinx via py-stevedore via py-e3-core

post-extract:
	${RM} ${WRKSRC}/src/e3/py.typed

post-install:
.for bin in e3-convert-xunit e3-find-skipped-tests e3-opt-check e3-opt-parser \
	e3-run-test-fragment e3-test e3-testsuite-report
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"

.include "../../mk/bsd.pkg.mk"
