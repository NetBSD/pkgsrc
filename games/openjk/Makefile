# $NetBSD: Makefile,v 1.7 2022/08/11 05:08:33 gutteridge Exp $

DISTNAME=	openjk-0.0.0.20191030
PKGREVISION=	6
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=JACoders/}
GITHUB_PROJECT=	OpenJK
GITHUB_TAG=	4881be7478a833791d127fce7563de252d2246f7

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/JACoders/OpenJK
COMMENT=	Community version of the Star Wars: Jedi Academy game engine
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

TOOL_DEPENDS+=	icoutils-[0-9]*:../../graphics/icoutils

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++11

# C++11
GCC_REQD+=	4.7

CMAKE_ARGS+=	-DJK2InstallDir="share/JediAcademy"

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Darwin"
CXXFLAGS+=	-I${BUILDLINK_DIR}/include/GL
.else
CMAKE_ARGS+=	-DUseInternalJPEG=OFF
.endif

.if ${MACHINE_ARCH} == "i386" && ${OPSYS} == "Darwin"
OPENJK_ARCH=	x86
.elif ${MACHINE_ARCH} == "powerpc"
OPENJK_ARCH=	ppc
.elif !empty(MACHINE_ARCH:Mpowerpc64*)
OPENJK_ARCH=	ppc64
.elif !empty(MACHINE_ARCH:M*arm*)
OPENJK_ARCH=	arm
.else
OPENJK_ARCH=	${MACHINE_ARCH}
.endif

PLIST_SUBST+=	OPENJK_ARCH=${OPENJK_ARCH}

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications

post-build:
.for bin in openjk openjk_sp openjkded
	${SED}	-e 's,@PREFIX@,${PREFIX},g' \
		-e 's,@OPENJK_BIN@,${bin}.${OPENJK_ARCH},g' \
		${FILESDIR}/openjk.sh.in > ${WRKDIR}/${bin}
.endfor
.for s in 256 128 64 48 32 16
	${PREFIX}/bin/icotool -x -w ${s} -h ${s} -o ${WRKDIR}/${s}.png \
	    ${WRKSRC}/shared/icons/icon.ico
.endfor

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/openjk ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/openjk_sp ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/openjkded ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/openjk.desktop ${DESTDIR}${PREFIX}/share/applications
.for s in 256 128 64 48 32 16
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps
	${INSTALL_DATA} ${WRKDIR}/${s}.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/${s}x${s}/apps/openjk.png
.endfor

.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
