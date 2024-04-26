# $NetBSD: Makefile,v 1.1 2024/04/26 09:04:31 nia Exp $

DISTNAME=	PicoDrive_1.93
PKGNAME=	${DISTNAME:tl:S/_/-/1}
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=notaz/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/notaz/picodrive
COMMENT=	Fast Sega Mega Drive/MegaCD/32X emulator
LICENSE=	mame-license

WRKSRC=		${WRKDIR}/PicoDrive-${PKGVERSION_NOREV}

HAS_CONFIGURE=	yes
USE_TOOLS+=	gmake

CFLAGS+=	-DPICO_DATA_DIR="\"${PREFIX}/share/picodrive/\""

SOUND_DRIVERS+=	sdl

.include "Makefile.common"
.include "options.mk"

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} != "none"
SOUND_DRIVERS+=		oss
LDFLAGS+=		${LIBOSSAUDIO}
SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_MESSAGE.oss=	Correcting the path to the OSS device.
SUBST_FILES.oss+=	platform/libpicofe/linux/sndout_oss.c
SUBST_SED.oss+=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
.endif

CONFIGURE_ENV+=		SDL_CONFIG=${PREFIX}/bin/sdl-config

CONFIGURE_ARGS+=	--platform=generic
CONFIGURE_ARGS+=	--sound-drivers=${SOUND_DRIVERS:Q}

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/picodrive/skin
INSTALLATION_DIRS+=	share/pixmaps

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/PicoDrive \
		${DESTDIR}${PREFIX}/bin/picodrive
	${INSTALL_DATA} ${FILESDIR}/picodrive.desktop \
		${DESTDIR}${PREFIX}/share/applications/picodrive.desktop
	${INSTALL_DATA} ${WRKSRC}/platform/opendingux/data/megadrive.png \
		${DESTDIR}${PREFIX}/share/pixmaps/picodrive.png
	${INSTALL_DATA} ${WRKSRC}/platform/gp2x/skin/*.png \
		${DESTDIR}${PREFIX}/share/picodrive/skin
	${INSTALL_DATA} ${WRKSRC}/platform/gp2x/skin/*.txt \
		${DESTDIR}${PREFIX}/share/picodrive/skin

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/bsd.pkg.mk"
