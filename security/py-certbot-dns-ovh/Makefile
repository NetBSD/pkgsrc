# $NetBSD: Makefile,v 1.17 2022/03/17 12:23:32 adam Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot-dns-ovh-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-dns-ovh/}

COMMENT=	OVH DNS Authenticator plugin for Certbot

DEPENDS+=	${PYPKGPREFIX}-acme>=${CERTBOT_VERSION}:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-certbot>=${CERTBOT_VERSION}:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-lexicon>=3.2.1:../../net/py-lexicon

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
