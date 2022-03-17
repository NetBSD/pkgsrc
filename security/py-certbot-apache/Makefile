# $NetBSD: Makefile,v 1.17 2022/03/17 12:23:31 adam Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot-apache-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-apache/}

COMMENT=	Apache plugin for Certbot

DEPENDS+=	${PYPKGPREFIX}-acme>=${CERTBOT_VERSION}:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-augeas-[0-9]*:../../sysutils/py-augeas
DEPENDS+=	${PYPKGPREFIX}-certbot>=${CERTBOT_VERSION}:../../security/py-certbot

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
