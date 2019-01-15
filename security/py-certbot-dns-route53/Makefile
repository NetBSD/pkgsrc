# $NetBSD: Makefile,v 1.1 2019/01/15 09:38:10 triaxx Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/certbot/certbot-dns-route53/}
CATEGORIES=	security

COMMENT=	Amazon Web Services Route 53 API plugin for Certbot
MAINTAINER=	triaxx@NetBSD.org
LICENSE=	apache-2.0

.include "../../security/py-certbot/Makefile.common"

DEPENDS+=	${PYPKGPREFIX}-acme>=0.21.1:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-boto3-[0-9]*:../../net/py-boto3
DEPENDS+=	${PYPKGPREFIX}-certbot>=0.21.1:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface

EGG_NAME=	${DISTNAME:S/certbot/certbot_dns_route53/}

PYSETUPSUBDIR=	certbot-dns-route53

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
