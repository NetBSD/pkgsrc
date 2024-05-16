# $NetBSD: Makefile,v 1.52 2024/05/16 06:14:50 wiz Exp $

DISTNAME=	emulationstation-2.9.4
PKGREVISION=	18
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=RetroPie/}
GITHUB_PROJECT=	EmulationStation
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/RetroPie/EmulationStation
COMMENT=	Themeable multi-system emulator frontend
LICENSE=	mit

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES+=	c c++

USE_CXX_FEATURES+=	c++11

WRKSRC=		${WRKDIR}/EmulationStation-${PKGVERSION_NOREV}

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

# Deal with emulationstation's expectations for the location of the
# pugixml header.
post-configure:
	cd ${BUILDLINK_DIR} && ${MKDIR} -p include/pugixml/src
	cd ${BUILDLINK_DIR} && ${CP} include/pugixml.hpp include/pugixml/src/pugixml.hpp

post-install:
	${INSTALL_DATA} ${WRKSRC}/GAMELISTS.md ${WRKSRC}/README.md \
	    ${WRKSRC}/SYSTEMS.md ${WRKSRC}/THEMES.md \
	    ${DESTDIR}${PREFIX}/share/doc/emulationstation

.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../graphics/freeimage/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../multimedia/vlc/buildlink3.mk"
.include "../../textproc/pugixml/buildlink3.mk"
.include "../../textproc/rapidjson/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
