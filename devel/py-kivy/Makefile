# $NetBSD: Makefile,v 1.10 2024/01/30 14:21:43 ryoon Exp $

DISTNAME=	Kivy-2.2.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=K/Kivy/}

MAINTAINER=	kamel.derouiche@gmail.com
HOMEPAGE=	https://kivy.org/
COMMENT=	Library for rapid development of multitouch applications
LICENSE=	mit

USE_TOOLS+=	pkg-config

PYTHON_VERSIONS_INCOMPATIBLE=	27

# For share/kivy-examples
PYTHON_SELF_CONFLICT=	yes

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-kivy-garden-[0-9]*:../../devel/py-kivy-garden
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

# \todo Understand upstream's dependency rules and add/fix.
# (Upstream's docs are very confusing as they are not listed in a
# generic manner but only for a few specific operating systems, and
# blur what is in their wheels for various platforms vs what
# dependencies are needed.)
# \todo Consider options as audio/video may be too heavy.

DEPENDS+=	${PYPKGPREFIX}-game-[0-9]*:../../devel/py-game
DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils
# \todo File upstream bug that dependency on enchant is undocumented.
DEPENDS+=	${PYPKGPREFIX}-enchant>=1.6.5:../../textproc/py-enchant
DEPENDS+=	${PYPKGPREFIX}-pygments-[0-9]*:../../textproc/py-pygments

TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark-[0-9]*:../../devel/py-test-benchmark

# Despite bad permissions in the distfile, extraction seems to result
# in ok permissions, at least on NetBSD.  Commented out code remains
# because this is semi-likely to be an issue in some circumstances,
# and can be selectively re-enabled with an explanation.
#pre-configure:
#	${CHMOD} -R go-w ${WRKSRC}

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
