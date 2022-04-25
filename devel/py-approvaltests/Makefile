# $NetBSD: Makefile,v 1.39 2022/04/25 15:11:53 schmonz Exp $

DISTNAME=	approvaltests-5.0.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/approvaltests/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://approvaltests.com/
COMMENT=	Assertion/verification library to aid testing
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-allpairspy-[0-9]*:../../devel/py-allpairspy
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4-[0-9]*:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-empty-files-[0-9]*:../../devel/py-empty-files
DEPENDS+=	${PYPKGPREFIX}-pyperclip>=1.5.27:../../x11/py-pyperclip

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

# This is the officially documented method, but not all necessary files
# are in the pypi distfile (as of 3.5.0)
#TEST_DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox
#do-test:
#	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} ${PYTHONBIN} -m tox

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
