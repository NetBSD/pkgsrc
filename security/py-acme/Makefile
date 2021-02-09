# $NetBSD: Makefile,v 1.24 2021/02/09 10:06:41 adam Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	acme-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=a/acme/}

COMMENT=	ACME protocol implementation in Python

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=17.3.0:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-cryptography>=2.1.4:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-josepy>=1.1.0:../../security/py-josepy
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-requests>2.10:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-toolbelt>=0.3.0:../../devel/py-requests-toolbelt
DEPENDS+=	${PYPKGPREFIX}-rfc3339-[0-9]*:../../time/py-rfc3339
DEPENDS+=	${PYPKGPREFIX}-setuptools>=39.0.1:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-six>=1.11.0:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
