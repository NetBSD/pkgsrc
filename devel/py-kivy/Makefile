# $NetBSD: Makefile,v 1.32 2026/10/28 05:09:43 wiz Exp $

DISTNAME=	Kivy-2.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	9
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=K/Kivy/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://kivy.org/
COMMENT=	Library for rapid development of multitouch applications
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-packaging>=24.0:../../devel/py-packaging
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-filetype-[0-9]*:../../sysutils/py-filetype
DEPENDS+=	${PYPKGPREFIX}-kivy-garden>=0.1.4:../../devel/py-kivy-garden
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-requests-[0-9]*:../../devel/py-requests
# base
DEPENDS+=	${PYPKGPREFIX}-Pillow>=9.5.0:../../graphics/py-Pillow
# \todo File upstream bug that dependency on enchant and pygame is undocumented.
DEPENDS+=	${PYPKGPREFIX}-enchant>=1.6.5:../../textproc/py-enchant
DEPENDS+=	${PYPKGPREFIX}-game-[0-9]*:../../devel/py-game
TEST_DEPENDS+=	${PYPKGPREFIX}-responses-[0-9]*:../../net/py-responses
TEST_DEPENDS+=	${PYPKGPREFIX}-test-asyncio-[0-9]*:../../devel/py-test-asyncio
TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark-[0-9]*:../../devel/py-test-benchmark
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout-[0-9]*:../../devel/py-test-timeout

PYTHON_VERSIONS_INCOMPATIBLE=	311

# \todo Understand upstream's dependency rules and add/fix.
# (Upstream's docs are very confusing as they are not listed in a
# generic manner but only for a few specific operating systems, and
# blur what is in their wheels for various platforms vs what
# dependencies are needed.)
# \todo Consider options as audio/video may be too heavy.

USE_TOOLS+=	pkg-config

WHEEL_NAME=	${DISTNAME:tl}

# Despite bad permissions in the distfile, extraction seems to result
# in ok permissions, at least on NetBSD.  Commented out code remains
# because this is semi-likely to be an issue in some circumstances,
# and can be selectively re-enabled with an explanation.
#pre-configure:
#	${CHMOD} -R go-w ${WRKSRC}

# For share/kivy-examples
PYTHON_SELF_CONFLICT=	yes

SUBST_CLASSES+=		prefix
SUBST_VARS.prefix=	PREFIX
SUBST_FILES.prefix+=	kivy/core/text/__init__.py
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Fixing PREFIX.

post-install:
	${RM} ${DESTDIR}${PREFIX}/${PYSITELIB}/kivy/tests/common.py.orig
	${RM} ${DESTDIR}${PREFIX}/${PYSITELIB}/kivy/tests/conftest.py.orig
	${RM} ${DESTDIR}${PREFIX}/${PYSITELIB}/kivy/tests/fixtures.py.orig

# as of 2.3.1
# 19 failed, 873 passed, 23 skipped, 1 xfailed, 5 warnings

TEST_ENV+=	PYTHONPATH=${DESTDIR}${PREFIX}/${PYSITELIB}
# Run tests against destdir (after 'make package') to have compiled
# extension available; explicitly pass test directory to avoid
# automatic collection find examples/widgets/bubble_test.py first.
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} \
		pytest-${PYVERSSUFFIX} ${DESTDIR}${PREFIX}/${PYSITELIB}/kivy/tests

.include "../../mk/bsd.prefs.mk"

# Include various packages needed for SDL2.
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../audio/SDL2_sound/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../graphics/MesaLib/buildlink3.mk"
.endif
.include "../../lang/python/wheel.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
