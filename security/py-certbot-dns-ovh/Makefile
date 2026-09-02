# $NetBSD: Makefile,v 1.21 2026/09/02 09:13:21 adam Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot_dns_ovh-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-dns-ovh/}

COMMENT=	OVH DNS Authenticator plugin for Certbot

DEPENDS+=	${PYPKGPREFIX}-certbot>=${CERTBOT_VERSION}:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-lexicon>=3.15.1:../../net/py-lexicon

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
