# $NetBSD: Makefile,v 1.21 2022/07/07 10:27:14 adam Exp $

DISTNAME=	eyeD3-0.9.6
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eyed3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://eyed3.readthedocs.io/en/latest/
COMMENT=	Python audio data toolkit (ID3 and MP3)
LICENSE=	gnu-gpl-v3

EGG_NAME=	${DISTNAME:tl}

DEPENDS+=	${PYPKGPREFIX}-deprecation>=2.1.0:../../devel/py-deprecation
DEPENDS+=	${PYPKGPREFIX}-filetype>=1.0.7:../../sysutils/py-filetype
TEST_DEPENDS+=	${PYPKGPREFIX}-factory_boy>=3.1.0:../../devel/py-factory_boy
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8>=3.8.4:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=6.2.1:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.10.1:../../devel/py-test-cov

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
