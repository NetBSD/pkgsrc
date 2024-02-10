# $NetBSD: Makefile,v 1.14 2024/02/10 07:15:24 adam Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot-dns-linode-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-dns-linode/}

COMMENT=	Linode DNS Authenticator plugin for Certbot

DEPENDS+=	${PYPKGPREFIX}-acme>=${CERTBOT_VERSION}:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-certbot>=${CERTBOT_VERSION}:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-lexicon>=3.14.1:../../net/py-lexicon

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
