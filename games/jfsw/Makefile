# $NetBSD: Makefile,v 1.1 2026/05/04 12:28:52 nia Exp $

DISTNAME=	jfsw-20260105
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=jonof/}
GITHUB_PROJECT=	jfsw
GITHUB_TAG=	${PKGVERSION_NOREV}

GITHUB_SUBMODULES+= \
	jonof jfaudiolib 68be97f6d33d7be2421a6bea437f21c60d70f8bb jfaudiolib

GITHUB_SUBMODULES+= \
	jonof jfbuild 40a98be571e359a70fc60476899e4650e285dbca jfbuild

GITHUB_SUBMODULES+= \
	jonof jfmact 731c0cc4aabd3cc0f510c9322825f1b61b2e47b3 jfmact

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.jonof.id.au/jfsw/
COMMENT=	Shadow Warrior port for modern systems
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${GITHUB_TAG}

USE_TOOLS+=	gmake pkg-config
USE_LANGUAGES=	c c++

FORCE_C_STD=	gnu99 # alloca

MAKE_FLAGS+=	USE_ASM=0
MAKE_FLAGS+=	HAVE_GTK=0
MAKE_FLAGS+=	RENDERTYPE=SDL
MAKE_FLAGS+=	DATADIR=${PREFIX}/share/${PKGBASE}

MAKE_FLAGS.NetBSD+=	PLATFORM=BSD

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/${PKGBASE}
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pixmaps

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sw \
		${DESTDIR}${PREFIX}/bin/${PKGBASE}
	${INSTALL_PROGRAM} ${WRKSRC}/build \
		${DESTDIR}${PREFIX}/bin/${PKGBASE}-build
	${INSTALL_DATA} ${WRKSRC}/rsrc/game.png \
		${DESTDIR}${PREFIX}/share/pixmaps/${PKGBASE}.png
	${INSTALL_DATA} ${FILESDIR}/jfsw.desktop \
		${DESTDIR}${PREFIX}/share/applications/${PKGBASE}.desktop

.include "options.mk"
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Linux"
.  include "../../audio/alsa-lib/buildlink3.mk"
.endif
.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
