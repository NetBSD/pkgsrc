# $NetBSD: Makefile,v 1.60 2023/11/10 11:27:35 adam Exp $

DISTNAME=	google-auth-2.23.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=g/google-auth/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/googleapis/google-auth-library-python
COMMENT=	Google Authentication Library
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-asn1-modules>=0.2.1:../../security/py-asn1-modules
DEPENDS+=	${PYPKGPREFIX}-cachetools>=2.0.0:../../devel/py-cachetools
DEPENDS+=	${PYPKGPREFIX}-requests>=2.20.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-rsa>=3.1.4:../../security/py-rsa
TEST_DEPENDS+=	${PYPKGPREFIX}-flask-[0-9]*:../../www/py-flask
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-oauth2client-[0-9]*:../../security/py-oauth2client
TEST_DEPENDS+=	${PYPKGPREFIX}-responses-[0-9]*:../../net/py-responses
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-localserver-[0-9]*:../../devel/py-test-localserver
TEST_DEPENDS+=	${PYPKGPREFIX}-u2f-[0-9]*:../../security/py-u2f

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# hack
post-install:
	${RM} -r ${DESTDIR}${PREFIX}/${PYSITELIB}/build

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	cryptography OpenSSL
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
