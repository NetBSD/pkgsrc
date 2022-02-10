# $NetBSD: Makefile,v 1.9 2022/02/10 21:23:32 adam Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot-dns-dnsmadeeasy-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-dns-dnsmadeeasy/}

COMMENT=	DNS Made Easy DNS Authenticator plugin for Certbot

DEPENDS+=	${PYPKGPREFIX}-acme>=${CERTBOT_VERSION}:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-certbot>=${CERTBOT_VERSION}:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-lexicon>=3.2.1:../../net/py-lexicon
DEPENDS+=	${PYPKGPREFIX}-setuptools>=39.0.1:../../devel/py-setuptools

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
