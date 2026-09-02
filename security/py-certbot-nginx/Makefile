# $NetBSD: Makefile,v 1.32 2026/09/02 09:13:22 adam Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot_nginx-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-nginx/}

COMMENT=	Nginx plugin for Certbot

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=25.0.0:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-certbot>=${CERTBOT_VERSION}:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-pyparsing>=3.0.0:../../devel/py-pyparsing

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
