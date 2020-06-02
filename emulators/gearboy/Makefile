# $NetBSD: Makefile,v 1.1 2020/06/02 13:24:32 nia Exp $

.include "Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/drhelius/Gearboy
COMMENT=	Game Boy / Gameboy Color emulator
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake

BUILD_DIRS=	platforms/linux

MAKE_FLAGS+=	CXX=${CXX}
MAKE_FLAGS+=	GIT_VERSION="pkgsrc"

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
MAKE_FLAGS+=	UNAME_S="Linux"
.else
MAKE_FLAGS+=	UNAME_S="Darwin"
.endif

# alloca
BUILDLINK_TRANSFORM+=	opt:-std=c++11:-std=gnu++11

INSTALLATION_DIRS+=	bin share/applications share/pixmaps

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${BUILD_DIRS}/gearboy \
		${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/gearboy.desktop \
		${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/platforms/ios/Gearboy/Images.xcassets/AppIcon.appiconset/gb_icon_120.png \
		${DESTDIR}${PREFIX}/share/pixmaps/gearboy.png

.include "../../devel/SDL2/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.  include "../../graphics/glew/buildlink3.mk"
.  include "../../graphics/MesaLib/buildlink3.mk"
.endif
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/bsd.pkg.mk"
