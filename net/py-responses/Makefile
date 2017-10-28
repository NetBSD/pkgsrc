# $NetBSD: Makefile,v 1.1 2017/10/28 06:52:56 adam Exp $

DISTNAME=	responses-0.8.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=r/responses/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/getsentry/responses
COMMENT=	Utility library for mocking out the requests Python library
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-cookies-[0-9]*:../../www/py-cookies
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-requests>=2.0:../../devel/py-requests

.include "../../lang/python/pyversion.mk"

.if "${PYPKGPREFIX}" == "py27"
DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
.endif

BUILD_DEPENDS+=	${PYPKGPREFIX}-coverage>=3.7.1:../../devel/py-coverage
BUILD_DEPENDS+=	${PYPKGPREFIX}-flake8-[0-9]*:../../devel/py-flake8
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-localserver-[0-9]*:../../devel/py-test-localserver

USE_LANGUAGES=	# none

#post-install:
#	cd ${DESTDIR}${PREFIX}/bin && ${MV} tldextract tldextract${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
