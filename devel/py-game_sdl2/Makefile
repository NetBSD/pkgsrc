# $NetBSD: Makefile,v 1.4 2023/11/12 13:21:10 wiz Exp $

DISTNAME=	pygame_sdl2-2.1.0-for-renpy-8.0.3
PKGNAME=	${PYPKGPREFIX}-game_sdl2-2.1.0
PKGREVISION=	2
CATEGORIES=	devel games python
MASTER_SITES=	https://www.renpy.org/dl/8.0.3/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/renpy/pygame_sdl2
COMMENT=	Set of Python modules designed for writing games for RenPy
LICENSE=	gnu-lgpl-v2.1

PYTHON_VERSIONS_INCOMPATIBLE=	27

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython-[0-9]*:../../devel/py-cython

USE_TOOLS+=	pkg-config

EGG_NAME=	pygame_sdl2-${PKGVERSION_NOREV}

REPLACE_PYTHON+=	examples/*.py
REPLACE_PYTHON+=	setup.py

SUBST_CLASSES+=		cython
SUBST_STAGE.cython=	pre-configure
SUBST_MESSAGE.cython=	Use versioned cython_command
SUBST_FILES.cython+=	setuplib.py
SUBST_SED.cython=	-e 's,cython_command = ".*,cython_command = "cython-${PYVERSSUFFIX}",g'

.include "../../mk/bsd.prefs.mk"
PLIST_VARS+=		darwin unix
.if ${OPSYS} == "Darwin"
PLIST.darwin=		yes
.else
.  include "../../x11/libX11/buildlink3.mk"
PLIST.unix=		yes
.endif

post-extract:
	# Do not use pre-generated cython results.
	# *_api.h is missing and it faild in install stage.
	# These requires correct cython_dommand.
	${RM} -f ${WRKSRC}/gen/*
	${RM} -f ${WRKSRC}/gen3/*
	# Do not use invalid version number.
	${RM} -f ${WRKSRC}/setup.cfg

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
