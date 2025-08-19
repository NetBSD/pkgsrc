# $NetBSD: Makefile,v 1.68 2025/08/19 05:27:37 adam Exp $

DISTNAME=	requests-2.32.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel www python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://requests.readthedocs.io/
COMMENT=	HTTP library, written in Python, for human beings
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-certifi>=2017.4.17:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-charset-normalizer>=2:../../converters/py-charset-normalizer
DEPENDS+=	${PYPKGPREFIX}-idna>=2.5:../../www/py-idna
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.21.1:../../www/py-urllib3
TEST_DEPENDS+=	${PYPKGPREFIX}-Socks>=1.5.8:../../net/py-Socks
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-httpbin>=2.0.0:../../www/py-test-httpbin
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-trustme-[0-9]*:../../security/py-trustme

USE_LANGUAGES=		# none
REPLACE_PYTHON+=	requests/certs.py

# as of 2.32.4
# with default settings (no network access):
# 143 failed, 452 passed, 15 skipped, 1 xfailed, 14 warnings
# for testing:
#ALLOW_NETWORK_ACCESS=	yes
# 595 passed, 15 skipped, 1 xpassed, 18 warnings

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
