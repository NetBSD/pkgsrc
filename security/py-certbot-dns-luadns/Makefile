# $NetBSD: Makefile,v 1.17 2023/12/12 16:39:35 adam Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot-dns-luadns-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-dns-luadns/}

COMMENT=	LuaDNS Authenticator plugin for Certbot

DEPENDS+=	${PYPKGPREFIX}-acme>=${CERTBOT_VERSION}:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-certbot>=${CERTBOT_VERSION}:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-lexicon>=3.2.1:../../net/py-lexicon

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
