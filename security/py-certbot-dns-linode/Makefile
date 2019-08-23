# $NetBSD: Makefile,v 1.2 2019/08/23 09:57:50 adam Exp $

DISTNAME=	certbot-dns-linode-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-dns-linode/}

MAINTAINER=	triaxx@NetBSD.org
COMMENT=	Linode DNS Authenticator plugin for Certbot

.include "../../security/py-certbot/Makefile.common"

DEPENDS+=	${PYPKGPREFIX}-acme>=0.31.0:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-certbot>=0.34.0:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-lexicon>=2.2.3:../../net/py-lexicon
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
