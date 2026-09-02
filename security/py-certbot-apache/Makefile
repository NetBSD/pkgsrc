# $NetBSD: Makefile,v 1.22 2026/09/02 09:13:20 adam Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot_apache-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-apache/}

COMMENT=	Apache plugin for Certbot

DEPENDS+=	${PYPKGPREFIX}-augeas>=0:../../sysutils/py-augeas
DEPENDS+=	${PYPKGPREFIX}-certbot>=${CERTBOT_VERSION}:../../security/py-certbot

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
