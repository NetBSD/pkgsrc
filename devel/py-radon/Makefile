# $NetBSD: Makefile,v 1.18 2023/07/01 08:53:22 wiz Exp $

DISTNAME=	radon-5.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/radon/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://radon.readthedocs.org/
COMMENT=	Code Metrics in Python
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-mando>=0.6:../../devel/py-mando
DEPENDS+=	${PYPKGPREFIX}-colorama>=0.4.1:../../comms/py-colorama
DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} radon radon-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC}/radon/tests && ${SETENV} ${TEST_ENV} ${PYTHONBIN} run.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
