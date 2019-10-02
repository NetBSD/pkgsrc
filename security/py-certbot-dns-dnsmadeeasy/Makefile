# $NetBSD: Makefile,v 1.2 2019/10/02 17:36:43 adam Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot-dns-dnsmadeeasy-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-dns-dnsmadeeasy/}

COMMENT=	DNS Made Easy DNS Authenticator plugin for Certbot

DEPENDS+=	${PYPKGPREFIX}-acme>=0.31.0:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-certbot>=0.39.0:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-lexicon>=2.2.1:../../net/py-lexicon
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
