# $NetBSD: Makefile,v 1.41 2022/07/27 19:05:58 wiz Exp $

DISTNAME=	pygame-1.9.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	2
CATEGORIES=	devel games python
MASTER_SITES=	${MASTER_SITE_PYPI:=P/Pygame/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.pygame.org/
COMMENT=	Set of Python modules designed for writing games
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config

REPLACE_PYTHON+=	examples/*.py
REPLACE_PYTHON+=	setup.py

SUBST_CLASSES+=		fixpath
SUBST_STAGE.fixpath=	pre-configure
SUBST_MESSAGE.fixpath=	Fixing paths.
SUBST_FILES.fixpath=	buildconfig/config_darwin.py
SUBST_FILES.fixpath+=	buildconfig/config_unix.py
SUBST_SED.fixpath=	-e 's,/usr/local,${PREFIX},g'

.include "../../mk/bsd.prefs.mk"
PLIST_VARS+=		darwin unix
.if ${OPSYS} == "Darwin"
PLIST.darwin=		yes
.else
.  include "../../x11/libX11/buildlink3.mk"
PLIST.unix=		yes
.endif

# Disable video4linux
pre-configure:
	${RM} ${WRKSRC}/buildconfig/Setup_Unix.in
	${TOUCH} ${WRKSRC}/buildconfig/Setup_Unix.in

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
