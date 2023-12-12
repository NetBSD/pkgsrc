# $NetBSD: Makefile,v 1.33 2023/12/12 16:39:34 adam Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	acme-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=a/acme/}

COMMENT=	ACME protocol implementation in Python

DEPENDS+=	${PYPKGPREFIX}-josepy>=1.13.0:../../security/py-josepy
DEPENDS+=	${PYPKGPREFIX}-pytz>=2019.3:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-requests>=2.20.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-rfc3339-[0-9]*:../../time/py-rfc3339
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions

.include "../../lang/python/wheel.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography
PYTHON_VERSIONED_DEPENDENCIES+=	OpenSSL
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
