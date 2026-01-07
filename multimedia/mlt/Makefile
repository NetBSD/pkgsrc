# $NetBSD: Makefile,v 1.157 2026/01/07 08:48:09 wiz Exp $

PKGREVISION= 2
.include "Makefile.common"

COMMENT=	Open source multimedia framework

CMAKE_CONFIGURE_ARGS+=	-DMOD_VIDSTAB=OFF
CMAKE_CONFIGURE_ARGS+=	-DMOD_QT=OFF
CMAKE_CONFIGURE_ARGS+=	-DMOD_QT6=OFF

SUBST_CLASSES+=		frei0r
SUBST_STAGE.frei0r=	pre-configure
SUBST_FILES.frei0r=	src/modules/frei0r/factory.c
SUBST_SED.frei0r=	-e 's^/usr/lib/frei0r-1.*:^${BUILDLINK_PREFIX.frei0r}/lib/frei0r-1:^'

PKGCONFIG_OVERRIDE+=	src/framework/mlt-framework.pc.in
PKGCONFIG_OVERRIDE+=	src/mlt++/mlt++.pc.in

.include "../../devel/cmake/build.mk"
.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../audio/jack/buildlink3.mk"
.include "../../audio/ladspa/buildlink3.mk"
.include "../../audio/libebur128/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/rubberband/buildlink3.mk"
.include "../../audio/sox/buildlink3.mk"
.include "../../mk/bsd.prefs.mk"
.if !empty(PKGSRC_COMPILER:M*gcc*)
.  include "../../devel/libatomic/buildlink3.mk"
.endif
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../multimedia/ffmpeg7/buildlink3.mk"
.include "../../multimedia/frei0r/buildlink3.mk"
.include "../../multimedia/libdv/buildlink3.mk"
.include "../../multimedia/movit/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
