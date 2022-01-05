# $NetBSD: Makefile,v 1.19 2022/01/05 15:40:57 wiz Exp $

DISTNAME=	eyeD3-0.9.5
PKGREVISION=	3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_PYPI:=e/eyeD3/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://eyed3.readthedocs.io/en/latest/
COMMENT=	Python audio data toolkit (ID3 and MP3)
LICENSE=	gnu-gpl-v3

DEPENDS+=	${PYPKGPREFIX}-deprecation-[0-9]*:../../devel/py-deprecation
DEPENDS+=	${PYPKGPREFIX}-factory_boy-[0-9]*:../../devel/py-factory_boy
DEPENDS+=	${PYPKGPREFIX}-filetype-[0-9]*:../../sysutils/py-filetype
#TEST_DEPENDS+=	wget-[0-9]*:../../net/wget
#TEST_DEPENDS+=	${PYPKGPREFIX}-tox-[0-9]*:../../devel/py-tox

PYTHON_VERSIONED_DEPENDENCIES+=	test:test

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-faker via py-factory_boy

USE_PKG_RESOURCES=	yes

USE_LANGUAGES=	# none
USE_TOOLS+=	gmake

#SUBST_CLASSES+=		test
#SUBST_SED.test+=	-e "s,tox,tox-${PYVERSSUFFIX},g"
#SUBST_STAGE.test+=	pre-configure
#SUBST_FILES.test+=	Makefile

# tox-based testing
#do-test:
#	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} test-data test

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
