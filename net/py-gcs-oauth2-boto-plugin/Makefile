# $NetBSD: Makefile,v 1.8 2022/01/27 23:49:41 wiz Exp $

DISTNAME=	gcs-oauth2-boto-plugin-3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/gcs-oauth2-boto-plugin/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/GoogleCloudPlatform/gcs-oauth2-boto-plugin
COMMENT=	Boto auth plugin for Google Cloud Storage
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-boto>=2.29.1:../../net/py-boto
DEPENDS+=	${PYPKGPREFIX}-google-reauth>=0.1.0:../../security/py-google-reauth
DEPENDS+=	${PYPKGPREFIX}-httplib2>=0.18:../../www/py-httplib2
DEPENDS+=	${PYPKGPREFIX}-oauth2client>=2.2.0:../../security/py-oauth2client
DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.13:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-retry_decorator>=1.0.0:../../devel/py-retry_decorator
DEPENDS+=	${PYPKGPREFIX}-rsa>=4.7.2:../../security/py-rsa
DEPENDS+=	${PYPKGPREFIX}-six>=1.12.0:../../lang/py-six

TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-rsa

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
