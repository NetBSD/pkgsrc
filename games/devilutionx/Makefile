# $NetBSD: Makefile,v 1.1 2019/07/03 10:58:12 nia Exp $

DISTNAME=	devilutonx-0.4.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=diasurgical/}
GITHUB_PROJECT=	devilutionX

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/diasurgical/devilutionX
COMMENT=	Port of the RPG Diablo for modern operating systems
LICENSE=	unlicense

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${PKGVERSION_NOREV}

USE_CMAKE=	yes
USE_LANGUAGES=	c c++03

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"
CMAKE_ARGS+=	-DASAN=OFF
CMAKE_ARGS+=	-DDEBUG=OFF
CMAKE_ARGS+=	-DFASTER=OFF

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
CXXFLAGS+=	-DO_LARGEFILE=0 -Dstat64=stat -Dlstat64=lstat -Dlseek64=lseek -Doff64_t=off_t -Dfstat64=fstat -Dftruncate64=ftruncate
.endif

CXXFLAGS+=	-DASIO_DISABLE_STD_EXPERIMENTAL_STRING_VIEW=1

ICON_SIZES=	1024 512 256 128 64 32 16

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
.for i in ${ICON_SIZES}
INSTALLATION_DIRS+=	share/icons/hicolor/${i}x${i}/apps
.endfor

post-extract:
	${MV} ${WRKSRC}/Xcode/AppIcon.xcassets/AppIcon.appiconset/appicon-1.png \
	    ${WRKSRC}/Xcode/AppIcon.xcassets/AppIcon.appiconset/32.png

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/devilutionx ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/devilutionx.desktop \
	    ${DESTDIR}${PREFIX}/share/applications
.for i in ${ICON_SIZES}
	${INSTALL_DATA} ${WRKSRC}/Xcode/AppIcon.xcassets/AppIcon.appiconset/${i}.png \
	    ${DESTDIR}${PREFIX}/share/icons/hicolor/${i}x${i}/apps/devilutionx.png
.endfor

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../security/libsodium/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
