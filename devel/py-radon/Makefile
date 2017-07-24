# $NetBSD: Makefile,v 1.3 2017/07/24 16:44:31 adam Exp $

DISTNAME=	radon-2.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/radon/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://radon.readthedocs.org/
COMMENT=	Code Metrics in Python
LICENSE=	mit

# according to README, only mando is really necessary
DEPENDS+=	${PYPKGPREFIX}-mando>=0.6:../../devel/py-mando
# but these are in "requirements.txt"
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.3:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-flake8-polyfill-[0-9]*:../../devel/py-flake8-polyfill
# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
BUILD_DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} radon radon-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC}/radon/tests && ${SETENV} ${TEST_ENV} ${PYTHONBIN} run.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
