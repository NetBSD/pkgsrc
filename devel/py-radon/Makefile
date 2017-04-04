# $NetBSD: Makefile,v 1.1 2017/04/04 14:19:58 wiz Exp $

DISTNAME=	radon-1.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/radon/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://radon.readthedocs.org/
COMMENT=	Code Metrics in Python
LICENSE=	mit

# according to README, only mando is really necessary
DEPENDS+=	${PYPKGPREFIX}-mando>=0.4:../../devel/py-mando
# but these are in "requirements.txt"
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.3.2:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-flake8-polyfill>=1.0.1:../../devel/py-flake8-polyfill
# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
BUILD_DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox

USE_LANGUAGES=	# none

do-test:
	${RUN} cd ${WRKSRC}/radon/tests; ${SETENV} ${TEST_ENV} ${PYTHONBIN} run.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
