# $NetBSD: Makefile,v 1.5 2022/06/09 15:53:27 adam Exp $

DISTNAME=	trio-0.21.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=t/trio/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://github.com/python-trio/trio
COMMENT=	Friendly Python library for async concurrency and I/O
LICENSE=	mit OR apache-2.0

DEPENDS+=	${PYPKGPREFIX}-async_generator>=1.9:../../devel/py-async_generator
DEPENDS+=	${PYPKGPREFIX}-attrs>=19.2.0:../../devel/py-attrs
DEPENDS+=	${PYPKGPREFIX}-cffi>=1.14:../../devel/py-cffi
DEPENDS+=	${PYPKGPREFIX}-idna>=2.10:../../www/py-idna
DEPENDS+=	${PYPKGPREFIX}-outcome>=1.1.0:../../devel/py-outcome
DEPENDS+=	${PYPKGPREFIX}-sniffio>=1.2.0:../../misc/py-sniffio
DEPENDS+=	${PYPKGPREFIX}-sortedcontainers>=2.2.2:../../devel/py-sortedcontainers
TEST_DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
TEST_DEPENDS+=	${PYPKGPREFIX}-astor>=0.8.1:../../devel/py-astor
TEST_DEPENDS+=	${PYPKGPREFIX}-jedi-[0-9]*:../../editors/py-jedi
TEST_DEPENDS+=	${PYPKGPREFIX}-pylint-[0-9]*:../../devel/py-pylint
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-trustme-[0-9]*:../../security/py-trustme

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
