# $NetBSD: Makefile,v 1.1 2020/12/04 23:24:56 riastradh Exp $

GITHUB_PROJECT=	responses
GITHUB_TAG=	0.12.1
DISTNAME=	${GITHUB_TAG}
PKGNAME=	${PYPKGPREFIX}-${GITHUB_PROJECT}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=getsentry/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pypi.org/project/responses/
COMMENT=	Python utility library for mocking out requests
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-cookies>=0:../../www/py-cookies
DEPENDS+=	${PYPKGPREFIX}-mock>=0:../../devel/py-mock
DEPENDS+=	${PYPKGPREFIX}-requests>=2.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six>=0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-urllib3>=1.25.10:../../www/py-urllib3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools

TEST_DEPENDS+=	${PYPKGPREFIX}-flake8>=0:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-test-localserver>=0:../../devel/py-test-localserver
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=4.6:../../devel/py-test

do-test:
	${RUN} \
	cd ${WRKSRC} && \
	${SETENV} ${TEST_ENV} ${PYTHONBIN} -m pytest

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
