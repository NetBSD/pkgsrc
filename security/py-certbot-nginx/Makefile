# $NetBSD: Makefile,v 1.1 2019/01/15 12:05:47 triaxx Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/certbot/certbot-nginx/}
CATEGORIES=	security

COMMENT=	Nginx plugin for Certbot
MAINTAINER=	triaxx@NetBSD.org
LICENSE=	apache-2.0

.include "../../security/py-certbot/Makefile.common"

DEPENDS+=	${PYPKGPREFIX}-acme>=0.21.1:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-certbot>=0.21.1:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-pyparsing-[0-9]*:../../devel/py-pyparsing
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface

EGG_NAME=	${DISTNAME:S/certbot/certbot_nginx/}

PYSETUPSUBDIR=	certbot-nginx

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
