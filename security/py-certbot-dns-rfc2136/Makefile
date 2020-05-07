# $NetBSD: Makefile,v 1.10 2020/05/07 10:53:46 adam Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot-dns-rfc2136-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-dns-rfc2136/}

COMMENT=	RFC 2136 DNS Authenticator plugin for Certbot

DEPENDS+=	${PYPKGPREFIX}-acme>=0.29.0:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-certbot>=1.1.0:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
