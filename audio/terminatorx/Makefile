# $NetBSD: Makefile,v 1.79 2022/08/11 05:08:05 gutteridge Exp $

DISTNAME=	terminatorX-4.0.1
PKGNAME=	${DISTNAME:S/X/x/1}
PKGREVISION=	22
CATEGORIES=	audio
MASTER_SITES=	https://terminatorx.org/dist/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://terminatorx.org/
COMMENT=	Realtime audio synthesizer
LICENSE=	gnu-gpl-v2

DEPENDS+=	vorbis-tools-[0-9]*:../../audio/vorbis-tools

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++03

CONFIGURE_ARGS+=	--disable-gtktest
CONFIGURE_ARGS+=	--disable-scheduler

.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} == "none"
CONFIGURE_ARGS+=	--disable-oss
.else
CONFIGURE_ARGS+=	--enable-oss
LIBS+=			${LIBOSSAUDIO}
SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_FILES.oss=	src/tX_global.c
SUBST_SED.oss=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
SUBST_MESSAGE.oss=	Fixing hardcoded audio device.
.endif

SUBST_CLASSES+=		prefix
SUBST_STAGE.prefix=	pre-configure
SUBST_MESSAGE.prefix=	Setting path to PREFIX in source files.
SUBST_FILES.prefix+=	src/tX_global.c
SUBST_FILES.prefix+=	src/tX_ladspa.cc
SUBST_SED.prefix+=	-e "s|/usr/lib/ladspa|${PREFIX}/lib/ladspa|g"
SUBST_SED.prefix+=	-e "s|/usr/share/ladspa|${PREFIX}/share/ladspa|g"

.include "options.mk"
.include "../../audio/ladspa/buildlink3.mk"
.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../audio/sox/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../textproc/liblrdf/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
