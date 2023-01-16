# $NetBSD: Makefile,v 1.58 2023/01/16 18:38:04 schmonz Exp $

DISTNAME=	approvaltests-8.1.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=a/approvaltests/}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://approvaltests.com/
COMMENT=	Assertion/verification library to aid testing
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-allpairspy>=2.1.0:../../devel/py-allpairspy
DEPENDS+=	${PYPKGPREFIX}-approval-utilities>=7.4.0:../../devel/py-approval-utilities
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.4.0:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-empty-files>=0.0.3:../../devel/py-empty-files
# mrjob >= 0.7.4 (prod.extras)

.include "options.mk"

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
