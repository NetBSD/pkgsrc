# $NetBSD: Makefile,v 1.16 2026/09/02 09:13:21 adam Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot_dns_linode-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-dns-linode/}

COMMENT=	Linode DNS Authenticator plugin for Certbot

DEPENDS+=	${PYPKGPREFIX}-certbot>=${CERTBOT_VERSION}:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-lexicon>=3.14.1:../../net/py-lexicon

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
