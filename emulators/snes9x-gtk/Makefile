# $NetBSD: Makefile,v 1.63 2019/01/02 09:54:05 nia Exp $

.include "../../emulators/snes9x/Makefile.common"

PKGNAME=	snes9x-gtk-${SNES9X_VERSION}

MAINTAINER=	nia@NetBSD.org
COMMENT=	Super Nintendo Entertainment System (SNES) emulator (GUI version)

CONFIGURE_DIRS+=	gtk
BUILD_DIRS+=		gtk
GNU_CONFIGURE=		yes

USE_TOOLS+=	autoreconf autoconf automake pkg-config
USE_TOOLS+=	msgfmt xgettext msgmerge
USE_TOOLS+=	gawk

BUILD_DEPENDS+=		gettext-m4-[0-9]*:../../devel/gettext-m4

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} != "none"
SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_MESSAGE.oss=	Correct path to OSS device.
SUBST_FILES.oss+=	gtk/src/gtk_sound_driver_oss.cpp
SUBST_SED.oss=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
.endif

LIBS.SunOS+=		-lsocket -lnsl

BUILDLINK_TRANSFORM+=	rm:-ldl

pre-configure:
	cd ${WRKSRC}/gtk && ./autogen.sh

.include "options.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
