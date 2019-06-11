# $NetBSD: Makefile,v 1.1 2019/06/11 21:06:59 triaxx Exp $

DISTNAME=	certbot-dns-google-${CERTBOT_VERSION}
MASTER_SITES=	${MASTER_SITE_PYPI:=c/certbot-dns-google/}

MAINTAINER=	triaxx@NetBSD.org
COMMENT=	Google Cloud DNS Authenticator plugin for Certbot

.include "../../security/py-certbot/Makefile.common"

DEPENDS+=	${PYPKGPREFIX}-acme>=0.29.0:../../security/py-acme
DEPENDS+=	${PYPKGPREFIX}-certbot>=0.34.0:../../security/py-certbot
DEPENDS+=	${PYPKGPREFIX}-google-api-python-client>=1.5:../../www/py-google-api-python-client
DEPENDS+=	${PYPKGPREFIX}-httplib2-[0-9]*:../../www/py-httplib2
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-oauth2client>=2.0:../../security/py-oauth2client
DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-ZopeInterface-[0-9]*:../../devel/py-ZopeInterface

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
