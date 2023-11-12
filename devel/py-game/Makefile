# $NetBSD: Makefile,v 1.45 2023/11/12 13:21:10 wiz Exp $

DISTNAME=	pygame-2.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	devel games python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/Pygame/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.pygame.org/
COMMENT=	Set of Python modules designed for writing games
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel

USE_TOOLS+=	pkg-config

REPLACE_PYTHON+=	examples/*.py
REPLACE_PYTHON+=	setup.py

PYTHON_VERSIONS_INCOMPATIBLE=	27

SUBST_CLASSES+=		fixpath
SUBST_STAGE.fixpath=	pre-configure
SUBST_MESSAGE.fixpath=	Fixing paths.
SUBST_FILES.fixpath=	buildconfig/config_darwin.py
SUBST_FILES.fixpath+=	buildconfig/config_unix.py
SUBST_SED.fixpath=	-e 's,/usr/local,${PREFIX},g'

.include "../../mk/bsd.prefs.mk"
PLIST_VARS+=		darwin
.if ${OPSYS} == "Darwin"
PLIST.darwin=		yes
.else
.  include "../../x11/libX11/buildlink3.mk"
.endif

# Disable video4linux
pre-configure:
	${RM} ${WRKSRC}/buildconfig/Setup_Unix.in
	${TOUCH} ${WRKSRC}/buildconfig/Setup_Unix.in

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/wheel.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
