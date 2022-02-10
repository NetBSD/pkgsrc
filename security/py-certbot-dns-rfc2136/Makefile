# $NetBSD: Makefile,v 1.17 2022/02/10 21:23:33 adam Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot-dns-rfc2136-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-dns-rfc2136/}

COMMENT=	RFC 2136 DNS Authenticator plugin for Certbot

DEPENDS+=	${PYPKGPREFIX}-acme>=${CERTBOT_VERSION}:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-certbot>=${CERTBOT_VERSION}:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-dns>=1.15.0:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-setuptools>=39.0.1:../../devel/py-setuptools

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
