# $NetBSD: Makefile,v 1.7 2018/12/16 14:15:11 adam Exp $

DISTNAME=	radon-2.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/radon/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://radon.readthedocs.org/
COMMENT=	Code Metrics in Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-mando>=0.6:../../devel/py-mando
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.3:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-flake8-polyfill-[0-9]*:../../devel/py-flake8-polyfill
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && ${MV} radon radon-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC}/radon/tests && ${SETENV} ${TEST_ENV} ${PYTHONBIN} run.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
