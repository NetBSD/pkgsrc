# $NetBSD: Makefile,v 1.17 2026/09/02 09:13:21 adam Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot_dns_google-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-dns-google/}

COMMENT=	Google Cloud DNS Authenticator plugin for Certbot

DEPENDS+=	${PYPKGPREFIX}-certbot>=${CERTBOT_VERSION}:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-google-api-python-client>=1.6.5:../../www/py-google-api-python-client
DEPENDS+=	${PYPKGPREFIX}-google-auth>=2.16.0:../../security/py-google-auth

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
