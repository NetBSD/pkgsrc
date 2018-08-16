# $NetBSD: Makefile,v 1.16 2018/08/16 18:54:43 adam Exp $

DISTNAME=	abba19584636c28cd98e3810e857f493cb63d06c
PKGNAME=	emulationstation-2.0.0_rc1_20150210
PKGREVISION=	10
CATEGORIES=	emulators games
MASTER_SITES=	https://github.com/Aloshi/EmulationStation/archive/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.emulationstation.org/
COMMENT=	Themeable multi-system emulator frontend

LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES+=	c c++11
GCC_REQD+=	4.7 # C++11

WRKSRC=		${WRKDIR}/EmulationStation-${DISTNAME}

INSTALLATION_DIRS=	bin share/doc/emulationstation

SUBST_CLASSES+=		fceu
SUBST_STAGE.fceu=	pre-configure
SUBST_MESSAGE.fceu=	Adjusting config file path to retroarch backend
SUBST_FILES.fceu=	es-app/src/SystemData.cpp
SUBST_SED.fceu=		-e "s|~/cores/libretro-fceumm.so|${PREFIX}/lib/libretro/fceumm_libretro.so|"

SUBST_CLASSES+=		ra
SUBST_STAGE.ra=		pre-configure
SUBST_MESSAGE.ra=	Adjusting path to retroarch backends in documentation
SUBST_FILES.ra=		SYSTEMS.md
SUBST_SED.ra=		-e "s|/usr|${PREFIX}|"

SUBST_CLASSES+=		etc
SUBST_STAGE.etc=	pre-configure
SUBST_MESSAGE.etc=	Adjusting path to global configuration files
SUBST_FILES.etc=	es-app/src/SystemData.cpp es-core/src/ThemeData.cpp
SUBST_FILES.etc+=	GAMELISTS.md README.md THEMES.md
SUBST_SED.etc=		-e "s|/etc|${PKG_SYSCONFDIR}|"

SUBST_CLASSES+=		vc
SUBST_STAGE.vc=		pre-configure
SUBST_MESSAGE.vc=	Fixing path to VideoCore libraries
SUBST_FILES.vc=		CMakeLists.txt
SUBST_SED.vc+=		-e 's;/opt/vc;${PREFIX};g'

.include "options.mk"

post-install:
	${INSTALL_DATA} ${WRKSRC}/GAMELISTS.md ${WRKSRC}/README.md \
	    ${WRKSRC}/SYSTEMS.md ${WRKSRC}/THEMES.md \
	    ${DESTDIR}${PREFIX}/share/doc/emulationstation

.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/freeimage/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../math/eigen3/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
