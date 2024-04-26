# $NetBSD: Makefile,v 1.1 2024/04/26 09:10:10 nia Exp $

DISTNAME=	pcsx-rearmed-23
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_GITHUB:=notaz/}
GITHUB_PROJECT=	pcsx_rearmed
GITHUB_TAG=	r${PKGVERSION_NOREV}

GITHUB_SUBMODULES+=	rtissera libchdr a03e69319164f69d781ab8e453f8cf407387bd13 libchdr
GITHUB_SUBMODULES+=	notaz libpicofe 33787db41d955f8dcafe833097f2cc87d70186ec frontend/libpicofe

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://github.com/notaz/pcsx_rearmed
COMMENT=	Sony PlayStation emulator with optimizations for ARM
LICENSE=	gnu-gpl-v2

HAS_CONFIGURE=	yes
USE_TOOLS+=	gmake
USE_LANGUAGES=	c c++

CFLAGS+=	-DPICO_DATA_DIR="\"${PREFIX}/share/pcsx-rearmed/\""

PCSX_SOUND_DRIVERS+=	sdl

.include "options.mk"

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} != "none"
PCSX_SOUND_DRIVERS+=	oss
LDFLAGS+=		${LIBOSSAUDIO}
SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_MESSAGE.oss=	Correcting the path to the OSS device.
SUBST_FILES.oss+=	plugins/dfsound/oss.c
SUBST_SED.oss+=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
.endif

.include "../../mk/bsd.fast.prefs.mk"

.if ${MACHINE_ARCH} == "earmv7hf"
CFLAGS+=		-march=armv7-a+neon -mfpu=neon
CONFIGURE_ARGS+=	--gpu=neon
CONFIGURE_ARGS+=	--enable-neon
.else
CONFIGURE_ARGS+=	--gpu=peops
CONFIGURE_ARGS+=	--disable-neon
.endif

.if ${MACHINE_ARCH:M*earm*}
MAKE_FLAGS+=		ARCH=arm
MAKE_FLAGS+=		USE_DYNAREC=1
.endif

.if ${MACHINE_ARCH} == "aarch64"
MAKE_FLAGS+=		ARCH=aarch64
MAKE_FLAGS+=		USE_DYNAREC=1
.endif

MAKE_FLAGS+=		PLUGINS=
MAKE_FLAGS+=		EXTRA_LDFLAGS=

CONFIGURE_ARGS+=	--platform=generic
CONFIGURE_ARGS+=	--sound-drivers=${PCSX_SOUND_DRIVERS:Q}

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/applications
INSTALLATION_DIRS+=	share/pcsx-rearmed/skin
INSTALLATION_DIRS+=	share/pixmaps

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pcsx \
		${DESTDIR}${PREFIX}/bin/pcsx-rearmed
	${INSTALL_DATA} ${FILESDIR}/pcsx-rearmed.desktop \
		${DESTDIR}${PREFIX}/share/applications/pcsx-rearmed.desktop
	${INSTALL_DATA} ${WRKSRC}/frontend/pandora/pcsx.png \
		${DESTDIR}${PREFIX}/share/pixmaps/pcsx-rearmed.png
	${INSTALL_DATA} ${WRKSRC}/frontend/pandora/skin/*.png \
		${DESTDIR}${PREFIX}/share/pcsx-rearmed/skin
	${INSTALL_DATA} ${WRKSRC}/frontend/pandora/skin/*.txt \
		${DESTDIR}${PREFIX}/share/pcsx-rearmed/skin

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/bsd.pkg.mk"
