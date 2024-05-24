# $NetBSD: Makefile,v 1.62 2024/05/24 16:44:07 adam Exp $

DISTNAME=	requests-2.32.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel www python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/requests/}

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://requests.readthedocs.io/
COMMENT=	HTTP library, written in Python, for human beings
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
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

PYTHON_VERSIONED_DEPENDENCIES+=	cryptography

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
