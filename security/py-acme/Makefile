# $NetBSD: Makefile,v 1.13 2018/12/15 21:12:22 wiz Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/certbot/acme/}
CATEGORIES=	security

COMMENT=	ACME protocol implementation in Python
MAINTAINER=	fhajny@NetBSD.org
LICENSE=	apache-2.0

.include "../../security/py-certbot/Makefile.common"

DEPENDS+=	${PYPKGPREFIX}-cryptography>=0.8:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-josepy>=1.0.0:../../security/py-josepy
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.15:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-requests>2.10:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-toolbelt>=0.3.0:../../devel/py-requests-toolbelt
DEPENDS+=	${PYPKGPREFIX}-rfc3339-[0-9]*:../../time/py-rfc3339
DEPENDS+=	${PYPKGPREFIX}-six>1.9.0:../../lang/py-six

EGG_NAME=	${DISTNAME:S/certbot/acme/}

PYSETUPSUBDIR=	acme

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
