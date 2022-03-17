# $NetBSD: Makefile,v 1.12 2022/03/17 12:23:32 adam Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot-dns-google-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-dns-google/}

COMMENT=	Google Cloud DNS Authenticator plugin for Certbot

DEPENDS+=	${PYPKGPREFIX}-acme>=${CERTBOT_VERSION}:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-certbot>=${CERTBOT_VERSION}:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-google-api-python-client>=1.5.5:../../www/py-google-api-python-client
DEPENDS+=	${PYPKGPREFIX}-httplib2-[0-9]*:../../www/py-httplib2
DEPENDS+=	${PYPKGPREFIX}-oauth2client>=4.0:../../security/py-oauth2client

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
