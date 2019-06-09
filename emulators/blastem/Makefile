# $NetBSD: Makefile,v 1.1 2019/06/09 13:58:08 nia Exp $

DISTNAME=	8aeac7bd9fa7
PKGNAME=	blastem-0.6.2
CATEGORIES=	emulators
MASTER_SITES=	https://www.retrodev.com/repos/blastem/archive/
DIST_SUBDIR=	blastem

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://www.retrodev.com/blastem/
COMMENT=	Higly accurate Genesis/Mega Drive emulator
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/blastem-${DISTNAME}
USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c99

MAKE_FLAGS+=	HOST_ZLIB=1
MAKE_FLAGS+=	OPT=
MAKE_FLAGS+=	NOLTO=1
MAKE_FLAGS+=	DATA_PATH=${PREFIX}/share/blastem

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/blastem
INSTALLATION_DIRS+=	share/blastem/images
INSTALLATION_DIRS+=	share/blastem/shaders
INSTALLATION_DIRS+=	share/doc/blastem
INSTALLATION_DIRS+=	share/icons/hicolor/48x48/apps
INSTALLATION_DIRS+=	share/icons/hicolor/72x72/apps
INSTALLATION_DIRS+=	share/icons/hicolor/96x96/apps
INSTALLATION_DIRS+=	share/icons/hicolor/144x144/apps

# wants to use a JIT
NOT_PAX_MPROTECT_SAFE+=	bin/blastem

# only supports writing 64-bit and 32-bit x86 asm
# may support ARM in future
ONLY_FOR_PLATFORM=	*-*-x86_64 *-*-i386

pre-configure:
	${CP} ${FILESDIR}/blastem.desktop ${WRKDIR}/blastem.desktop

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dis \
	    ${DESTDIR}${PREFIX}/bin/blastem-dis
	${INSTALL_PROGRAM} ${WRKSRC}/zdis \
	    ${DESTDIR}${PREFIX}/bin/blastem-zdis
	${INSTALL_PROGRAM} ${WRKSRC}/stateview \
	    ${DESTDIR}${PREFIX}/bin/blastem-stateview
	${INSTALL_PROGRAM} ${WRKSRC}/vgmplay \
	    ${DESTDIR}${PREFIX}/bin/blastem-vgmplay
	${INSTALL_PROGRAM} ${WRKSRC}/blastem \
	    ${DESTDIR}${PREFIX}/bin/blastem
	${INSTALL_DATA} ${WRKSRC}/README \
	    ${DESTDIR}${PREFIX}/share/doc/blastem/README
	${INSTALL_DATA} ${WRKSRC}/COPYING \
	    ${DESTDIR}${PREFIX}/share/doc/blastem/COPYING
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG \
	    ${DESTDIR}${PREFIX}/share/doc/blastem/CHANGELOG
	${INSTALL_DATA} ${WRKSRC}/default.cfg \
	    ${DESTDIR}${PREFIX}/share/blastem/default.cfg
	${INSTALL_DATA} ${WRKSRC}/gamecontrollerdb.txt \
	    ${DESTDIR}${PREFIX}/share/blastem/gamecontrollerdb.txt
	${INSTALL_DATA} ${WRKSRC}/shaders/* \
	    ${DESTDIR}${PREFIX}/share/blastem/shaders
	${INSTALL_DATA} ${WRKSRC}/images/* \
	    ${DESTDIR}${PREFIX}/share/blastem/images
	${INSTALL_DATA} ${WRKSRC}/rom.db \
	    ${DESTDIR}${PREFIX}/share/blastem/rom.db
	${INSTALL_DATA} ${WRKSRC}/android/res/drawable-mdpi/ic_launcher.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/48x48/apps/blastem.png
	${INSTALL_DATA} ${WRKSRC}/android/res/drawable-hdpi/ic_launcher.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/72x72/apps/blastem.png
	${INSTALL_DATA} ${WRKSRC}/android/res/drawable-xhdpi/ic_launcher.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/96x96/apps/blastem.png
	${INSTALL_DATA} ${WRKSRC}/android/res/drawable-xxhdpi/ic_launcher.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/144x144/apps/blastem.png
	${INSTALL_DATA} ${WRKDIR}/blastem.desktop \
	    ${DESTDIR}${PREFIX}/share/applications/blastem.desktop

.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
