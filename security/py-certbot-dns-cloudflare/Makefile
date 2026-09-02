# $NetBSD: Makefile,v 1.5 2026/09/02 09:13:20 adam Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot_dns_cloudflare-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-dns-cloudflare/}

COMMENT=	Cloudflare DNS Authenticator plugin for Certbot

DEPENDS+=	${PYPKGPREFIX}-certbot>=${CERTBOT_VERSION}:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-cloudflare>=4.0:../../net/py-cloudflare

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
