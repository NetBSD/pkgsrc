# $NetBSD: Makefile,v 1.3 2025/04/28 09:02:34 adam Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot_dns_cloudflare-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-dns-cloudflare/}

COMMENT=	Cloudflare DNS Authenticator plugin for Certbot

DEPENDS+=	${PYPKGPREFIX}-acme>=${CERTBOT_VERSION}:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-certbot>=${CERTBOT_VERSION}:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-cloudflare>=2.19:../../net/py-cloudflare

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
