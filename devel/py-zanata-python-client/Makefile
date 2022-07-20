# $NetBSD: Makefile,v 1.17 2022/07/20 22:08:10 wiz Exp $

DISTNAME=	zanata-python-client-1.5.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=zanata/}
GITHUB_PROJECT=	zanata-python-client
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://zanata.org/
COMMENT=	Zanata translation service client written in Python
LICENSE=	gnu-gpl-v3 AND gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-httplib2-[0-9]*:../../www/py-httplib2
DEPENDS+=	${PYPKGPREFIX}-polib-[0-9]*:../../devel/py-polib
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-minimock-[0-9]*:../../devel/py-minimock
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock

PYTHON_VERSIONS_INCOMPATIBLE= 27
USE_LANGUAGES=	# none

# as of 1.5.3
# 21 failed, 18 passed
# probably because it would need a proper zanata server for testing
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} py.test-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
