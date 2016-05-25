# $NetBSD: Makefile,v 1.1 2016/05/25 18:18:16 fhajny Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/certbot/acme/}
CATEGORIES=	security

COMMENT=	ACME protocol implementation in Python
MAINTAINER=	filip@joyent.com
LICENSE=	apache-2.0

.include "../../security/py-certbot/Makefile.common"

DEPENDS+=	${PYPKGPREFIX}-asn1-[0-9]*:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-cryptography>=0.8:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-ndg_httpsclient-[0-9]*:../../security/py-ndg_httpsclient
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.15:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-rfc3339-[0-9]*:../../time/py-rfc3339
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-werkzeug-[0-9]*:../../www/py-werkzeug

EGG_NAME=	${DISTNAME:S/certbot/acme/}

PYSETUPSUBDIR=	acme

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
