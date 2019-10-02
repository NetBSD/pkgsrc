# $NetBSD: Makefile,v 1.9 2019/10/02 17:36:44 adam Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot-nginx-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-nginx/}

COMMENT=	Nginx plugin for Certbot

DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-acme>=0.29.0:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-certbot>=0.37.0:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-pyparsing>=1.5.5:../../devel/py-pyparsing
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
