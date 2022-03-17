# $NetBSD: Makefile,v 1.16 2022/03/17 12:23:33 adam Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot-dns-route53-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-dns-route53/}

COMMENT=	Amazon Web Services Route 53 API plugin for Certbot

DEPENDS+=	${PYPKGPREFIX}-acme>=${CERTBOT_VERSION}:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-boto3>=1.15.15:../../net/py-boto3
DEPENDS+=	${PYPKGPREFIX}-certbot>=${CERTBOT_VERSION}:../../security/py-certbot

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
