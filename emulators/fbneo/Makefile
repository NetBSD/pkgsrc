# $NetBSD: Makefile,v 1.2 2024/01/30 14:21:46 ryoon Exp $

DISTNAME=	FBNeo-1.0.0.2
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=finalburnneo/}
GITHUB_PROJECT=	fbneo
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/finalburnneo/FBNeo
COMMENT=	FinalBurn Neo - the arcade game emulator (SDL2 version)
LICENSE=	fbalpha-license

USE_TOOLS+=	gmake perl
MAKE_FILE=	makefile

WRKSRC=		${WRKDIR}/${DISTNAME}

BUILD_TARGET=	sdl2

MAKE_FLAGS+=	RELEASEBUILD=1
MAKE_FLAGS+=	FORCE_SYSTEM_LIBPNG=1
MAKE_FLAGS+=	INCLUDE_7Z_SUPPORT=1
MAKE_FLAGS+=	PERL=1

REPLACE_PERL+=	src/dep/scripts/*.pl

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
MAKE_FLAGS+=	LSB_FIRST=1
TOOL_DEPENDS+=	nasm-[0-9]*:../../devel/nasm
.endif

LDFLAGS+=	-lpng -lz

MAKE_JOBS_SAFE=	no

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fbneo ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/fbneo.desktop ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/projectfiles/xcode/Emulator/Assets.xcassets/AppIcon.appiconset/icon_128.png \
		${DESTDIR}${PREFIX}/share/pixmaps/fbneo.png

.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
