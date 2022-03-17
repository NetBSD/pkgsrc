# $NetBSD: Makefile,v 1.8 2022/03/17 12:23:32 adam Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot-dns-digitalocean-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-dns-digitalocean/}

COMMENT=	DigitalOcean DNS Authenticator plugin for Certbot

DEPENDS+=	${PYPKGPREFIX}-acme>=${CERTBOT_VERSION}:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-certbot>=${CERTBOT_VERSION}:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-digitalocean>=1.11:../../net/py-digitalocean

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
