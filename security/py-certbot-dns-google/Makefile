# $NetBSD: Makefile,v 1.13 2023/05/12 09:17:14 adam Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot-dns-google-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-dns-google/}

COMMENT=	Google Cloud DNS Authenticator plugin for Certbot

DEPENDS+=	${PYPKGPREFIX}-acme>=${CERTBOT_VERSION}:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-certbot>=${CERTBOT_VERSION}:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-google-api-python-client>=1.6.5:../../www/py-google-api-python-client
DEPENDS+=	${PYPKGPREFIX}-google-oautht>=2.16.0:../../security/py-google-auth

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
