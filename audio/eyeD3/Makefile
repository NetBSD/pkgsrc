# $NetBSD: Makefile,v 1.15 2020/05/20 07:06:41 wiz Exp $

DISTNAME=	eyeD3-0.9.5
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eyeD3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://eyed3.readthedocs.io/en/latest/
COMMENT=	Python audio data toolkit (ID3 and MP3)
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-deprecation-[0-9]*:../../devel/py-deprecation
DEPENDS+=	${PYPKGPREFIX}-factory_boy-[0-9]*:../../devel/py-factory_boy
DEPENDS+=	${PYPKGPREFIX}-filetype-[0-9]*:../../sysutils/py-filetype

PYTHON_VERSIONED_DEPENDENCIES+=	test:test

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-faker via py-factory_boy

USE_LANGUAGES=			# none

# 13 test failures as of 0.9.5
# https://github.com/nicfit/eyeD3/issues/437
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} py.test-${PYVERSSUFFIX}

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
