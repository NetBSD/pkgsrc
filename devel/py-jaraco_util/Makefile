# $NetBSD: Makefile,v 1.8 2022/01/04 20:53:13 wiz Exp $

DISTNAME=	jaraco.util-11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/./_/}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jaraco.util/}
EXTRACT_SUFX=	.zip

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	https://pypi.python.org/pypi/jaraco.util
COMMENT=	General utility modules that supply commonly-used functionality
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-six>=1.4.1:../../lang/py-six
BUILD_DEPENDS+=	${PYPKGPREFIX}-hgtools-[0-9]*:../../devel/py-hgtools
TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=2.0:../../devel/py-test

USE_LANGUAGES=	# none

REPLACE_PYTHON+=	jaraco/lang/python.py

do-test:
	cd ${WRKSRC} && py.test-${PYVERSSUFFIX}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
