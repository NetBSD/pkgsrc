# $NetBSD: Makefile,v 1.2 2024/06/06 12:05:45 adam Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot_dns_cloudflare-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-dns-cloudflare/}

COMMENT=	Cloudflare DNS Authenticator plugin for Certbot

DEPENDS+=	${PYPKGPREFIX}-acme>=${CERTBOT_VERSION}:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-certbot>=${CERTBOT_VERSION}:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-cloudflare>=1.5.1:../../net/py-cloudflare

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
