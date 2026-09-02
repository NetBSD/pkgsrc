# $NetBSD: Makefile,v 1.22 2026/09/02 09:13:21 adam Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot_dns_rfc2136-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-dns-rfc2136/}

COMMENT=	RFC 2136 DNS Authenticator plugin for Certbot

DEPENDS+=	${PYPKGPREFIX}-certbot>=${CERTBOT_VERSION}:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-dns>=2.6.1:../../net/py-dns

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
