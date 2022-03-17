# $NetBSD: Makefile,v 1.28 2022/03/17 12:23:31 adam Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	acme-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=a/acme/}

COMMENT=	ACME protocol implementation in Python

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=17.3.0:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-cryptography>=2.5.0:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-josepy>=1.13.0:../../security/py-josepy
DEPENDS+=	${PYPKGPREFIX}-pytz>=2019.3:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-requests>=2.20.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-toolbelt>=0.3.0:../../devel/py-requests-toolbelt
DEPENDS+=	${PYPKGPREFIX}-rfc3339-[0-9]*:../../time/py-rfc3339
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-typing-extensions-[0-9]*:../../devel/py-typing-extensions

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
