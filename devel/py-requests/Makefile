# $NetBSD: Makefile,v 1.32 2017/05/31 06:30:25 adam Exp $

DISTNAME=	requests-2.17.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel www
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://docs.python-requests.org/en/latest/
COMMENT=	HTTP library, written in Python, for human beings
LICENSE=	apache-2.0

USE_LANGUAGES=		# none
REPLACE_PYTHON+=	requests/certs.py
REPLACE_PYTHON+=	tests/test_requests.py

DEPENDS+=	${PYPKGPREFIX}-certifi>=2017.4.17:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-chardet>=3.0.2:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-cryptography>=1.3.4:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.14:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-idna>=2.5:../../www/py-idna
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.12.1:../../www/py-urllib3

BUILD_DEPENDS+=	${PYPKGPREFIX}-Socks>=1.5.6:../../net/py-Socks
BUILD_DEPENDS+=	${PYPKGPREFIX}-test>=2.8.0:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-httpbin-[0-9]*:../../www/py-test-httpbin
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
