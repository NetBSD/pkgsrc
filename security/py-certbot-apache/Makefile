# $NetBSD: Makefile,v 1.21 2024/10/14 06:08:40 wiz Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot_apache-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-apache/}

COMMENT=	Apache plugin for Certbot

DEPENDS+=	${PYPKGPREFIX}-acme>=${CERTBOT_VERSION}:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-augeas-[0-9]*:../../sysutils/py-augeas
DEPENDS+=	${PYPKGPREFIX}-certbot>=${CERTBOT_VERSION}:../../security/py-certbot

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
