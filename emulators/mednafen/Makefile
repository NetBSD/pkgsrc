# $NetBSD: Makefile,v 1.38 2022/01/19 21:56:43 nia Exp $

DISTNAME=	mednafen-1.29.0
CATEGORIES=	emulators
MASTER_SITES=	https://mednafen.github.io/releases/files/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://mednafen.github.io/
COMMENT=	Portable multi-system emulator
LICENSE=	gnu-gpl-v2

CONFIGURE_ARGS+=	--with-external-mpcdec
CONFIGURE_ARGS+=	--with-external-tremor
CONFIGURE_ARGS+=	--with-external-trio
CONFIGURE_ARGS+=	--with-external-libzstd
CONFIGURE_ARGS+=	--with-external-lzo
CONFIGURE_ARGS+=	--disable-alsatest
CONFIGURE_ARGS+=	--disable-sdltest
CONFIGURE_ARGS+=	--disable-sdlframework

WRKSRC=			${WRKDIR}/mednafen
GNU_CONFIGURE=		yes
USE_TOOLS+=		intltool pkg-config
USE_TOOLS+=		msgfmt msgmerge xgettext
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
INSTALLATION_DIRS=	share/doc/mednafen

GCC_REQD+=		4.7 # gnu++11

# Complains, loudly.
MKPIE_SUPPORTED=	no

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} != "none"
SUBST_CLASSES+=		dsp
SUBST_STAGE.dsp=	pre-configure
SUBST_MESSAGE.dsp=	Fixing path to audio device.
SUBST_FILES.dsp=	src/sexyal/drivers/oss.cpp src/sexyal/sexyal.cpp
SUBST_SED.dsp=		-e s,/dev/dsp,${DEVOSSAUDIO},

LDFLAGS+=		${LIBOSSAUDIO}
.endif

post-install:
	${INSTALL_DATA} ${WRKSRC}/Documentation/*.html \
		${DESTDIR}${PREFIX}/share/doc/mednafen

.include "options.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../archivers/zstd/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/musepack/buildlink3.mk"
.include "../../audio/tremor/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/trio/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
