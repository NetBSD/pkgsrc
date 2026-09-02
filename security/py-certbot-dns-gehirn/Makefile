# $NetBSD: Makefile,v 1.15 2026/09/02 09:13:21 adam Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot_dns_gehirn-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-dns-gehirn/}

COMMENT=	Gehirn Infrastracture Service DNS Authenticator plugin for Certbot

DEPENDS+=	${PYPKGPREFIX}-certbot>=${CERTBOT_VERSION}:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-lexicon>=3.14.1:../../net/py-lexicon

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
