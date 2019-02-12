# $NetBSD: Makefile,v 1.3 2019/02/12 12:56:31 adam Exp $

DISTNAME=	certbot-dns-rfc2136-0.31.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-dns-rfc2136/}

COMMENT=	RFC 2136 DNS Authenticator plugin for Certbot
MAINTAINER=	triaxx@NetBSD.org
HOMEPAGE=	https://github.com/certbot/certbot
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-acme>=0.21.1:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-certbot>=0.21.1:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface

USE_LANGUAGES=	# none

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
