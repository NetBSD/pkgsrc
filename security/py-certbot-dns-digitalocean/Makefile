# $NetBSD: Makefile,v 1.11 2025/07/05 11:44:12 wiz Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot_dns_digitalocean-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-dns-digitalocean/}

COMMENT=	DigitalOcean DNS Authenticator plugin for Certbot

DEPENDS+=	${PYPKGPREFIX}-acme>=${CERTBOT_VERSION}:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-certbot>=${CERTBOT_VERSION}:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-digitalocean>=1.11:../../net/py-digitalocean

PYTHON_VERSIONS_INCOMPATIBLE=	39 310

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
