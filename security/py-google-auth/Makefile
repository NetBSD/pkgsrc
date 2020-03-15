# $NetBSD: Makefile,v 1.11 2020/03/15 19:56:29 wiz Exp $

DISTNAME=	google-auth-1.11.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/google-auth/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/googleapis/google-auth-library-python
COMMENT=	Google Authentication Library
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-asn1-modules>=0.2.1:../../security/py-asn1-modules
DEPENDS+=	${PYPKGPREFIX}-cachetools>=2.0.0:../../devel/py-cachetools
DEPENDS+=	${PYPKGPREFIX}-rsa>=3.1.4:../../security/py-rsa
DEPENDS+=	${PYPKGPREFIX}-setuptools>=40.3.0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-six>=1.9.0:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-oauth2client-[0-9]*:../../security/py-oauth2client
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-localserver-[0-9]*:../../devel/py-test-localserver

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-cachetools

USE_LANGUAGES=	# none

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
