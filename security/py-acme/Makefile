# $NetBSD: Makefile,v 1.40 2026/09/02 09:13:20 adam Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	acme-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=a/acme/}

COMMENT=	ACME protocol implementation in Python

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=25.0.0:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-cryptography>=47.0.0:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-josepy>=2.0.0:../../security/py-josepy
DEPENDS+=	${PYPKGPREFIX}-requests>=2.25.1:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-rfc3339>=0:../../time/py-rfc3339
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=0:../../devel/py-test-xdist
TEST_DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=0:../../devel/py-typing-extensions

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
