# $NetBSD: Makefile,v 1.17 2024/08/10 07:14:15 wiz Exp $

DISTNAME=	dropbox-12.0.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dropbox/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.dropbox.com/developers
COMMENT=	Dropbox Python API
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-requests>=2.16.2:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-six>=1.12.0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-stone>=2.0:../../net/py-stone
#TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
#TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
#TEST_DEPENDS+=	${PYPKGPREFIX}-mock-[0-9]*:../../devel/py-mock

PYTHON_VERSIONS_INCOMPATIBLE=	27

USE_LANGUAGES=	# none

# tests not included in pypi distfile
#do-test:
#	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
