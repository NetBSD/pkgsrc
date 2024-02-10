# $NetBSD: Makefile,v 1.1 2024/02/10 07:15:23 adam Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot-dns-cloudflare-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-dns-cloudflare/}

COMMENT=	Cloudflare DNS Authenticator plugin for Certbot

DEPENDS+=	${PYPKGPREFIX}-acme>=${CERTBOT_VERSION}:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-certbot>=${CERTBOT_VERSION}:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-cloudflare>=1.5.1:../../net/py-cloudflare

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
