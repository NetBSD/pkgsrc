# $NetBSD: Makefile,v 1.14 2026/09/02 09:13:20 adam Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot_dns_digitalocean-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-dns-digitalocean/}

COMMENT=	DigitalOcean DNS Authenticator plugin for Certbot

DEPENDS+=	${PYPKGPREFIX}-certbot>=${CERTBOT_VERSION}:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-digitalocean>=1.15:../../net/py-digitalocean

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
