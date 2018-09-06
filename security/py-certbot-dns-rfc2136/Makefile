# $NetBSD: Makefile,v 1.2 2018/09/06 12:26:43 fhajny Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/certbot/certbot-dns-rfc2136/}
CATEGORIES=	security

COMMENT=	RFC 2136 DNS Authenticator plugin for Certbot
MAINTAINER=	triaxx@NetBSD.org
LICENSE=	apache-2.0

.include "../../security/py-certbot/Makefile.common"

DEPENDS+=	${PYPKGPREFIX}-acme>=0.21.1:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-certbot>=0.21.1:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface

EGG_NAME=	${DISTNAME:S/certbot/certbot_dns_rfc2136/}

PYSETUPSUBDIR=	certbot-dns-rfc2136

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
