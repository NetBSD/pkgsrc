# $NetBSD: Makefile,v 1.20 2024/06/06 12:05:46 adam Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot_dns_rfc2136-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-dns-rfc2136/}

COMMENT=	RFC 2136 DNS Authenticator plugin for Certbot

DEPENDS+=	${PYPKGPREFIX}-acme>=${CERTBOT_VERSION}:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-certbot>=${CERTBOT_VERSION}:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-dns>=1.15.0:../../net/py-dns

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
