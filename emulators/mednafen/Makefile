# $NetBSD: Makefile,v 1.27 2019/10/01 19:37:50 nia Exp $

DISTNAME=	mednafen-1.22.2
CATEGORIES=	emulators
MASTER_SITES=	https://mednafen.github.io/releases/files/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://mednafen.github.io/
COMMENT=	Portable multi-system emulator
LICENSE=	gnu-gpl-v2

CONFIGURE_ARGS+=	--with-external-tremor
CONFIGURE_ARGS+=	--with-external-lzo

WRKSRC=			${WRKDIR}/mednafen
GNU_CONFIGURE=		yes
USE_TOOLS+=		intltool pkg-config
USE_LANGUAGES=		c c++03
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
INSTALLATION_DIRS=	share/doc/mednafen

SUBST_CLASSES+=		dsp
SUBST_STAGE.dsp=	pre-configure
SUBST_MESSAGE.dsp=	Fixing path to audio device.
SUBST_FILES.dsp=	src/sexyal/drivers/oss.cpp src/sexyal/sexyal.cpp
SUBST_SED.dsp=		-e s,/dev/dsp,${DEVOSSAUDIO},

post-install:
	${INSTALL_DATA} ${WRKSRC}/Documentation/*.html \
		${DESTDIR}${PREFIX}/share/doc/mednafen

.include "options.mk"
.include "../../archivers/lzo/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/tremor/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
