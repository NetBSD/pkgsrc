# $NetBSD: Makefile,v 1.7 2017/05/11 08:23:35 fhajny Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/certbot/acme/}
CATEGORIES=	security

COMMENT=	ACME protocol implementation in Python
MAINTAINER=	filip@joyent.com
LICENSE=	apache-2.0

.include "../../security/py-certbot/Makefile.common"

DEPENDS+=	${PYPKGPREFIX}-cryptography>=0.8:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.15:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-pytz-[0-9]*:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-requests>2.10:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-rfc3339-[0-9]*:../../time/py-rfc3339
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six

EGG_NAME=	${DISTNAME:S/certbot/acme/}

# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-pbr-[0-9]*:../../devel/py-pbr

PYSETUPSUBDIR=	acme

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/jws \
		${DESTDIR}${PREFIX}/bin/jws${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
