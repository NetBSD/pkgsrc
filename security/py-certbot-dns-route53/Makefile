# $NetBSD: Makefile,v 1.13 2021/08/05 10:52:01 adam Exp $

.include "../../security/py-certbot/Makefile.common"

DISTNAME=	certbot-dns-route53-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-dns-route53/}

COMMENT=	Amazon Web Services Route 53 API plugin for Certbot

DEPENDS+=	${PYPKGPREFIX}-acme>=${CERTBOT_VERSION}:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-boto3-[0-9]*:../../net/py-boto3
DEPENDS+=	${PYPKGPREFIX}-certbot>=${CERTBOT_VERSION}:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-setuptools>=39.0.1:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
