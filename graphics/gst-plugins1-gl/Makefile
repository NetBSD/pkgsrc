# $NetBSD: Makefile,v 1.9 2026/10/13 22:15:21 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-base/-gl/}
CATEGORIES=	graphics gnome

COMMENT=	Open source multimedia framework - GL plugin

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=	drm wayland

GST_EXT_BUILD=	# yes
.if ${OPSYS} != "Darwin"
GST_PLUGINS+=	drm
PLIST.drm=	yes
.endif
GST_PLUGINS+=	gl

.include "../../devel/wayland/platform.mk"
.if !empty(PLATFORM_SUPPORTS_WAYLAND:Myes)
PLIST.wayland=	yes
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.endif

# Because there is no "drm" dir.
GST_PLUGIN_DIRS=	gl

.PHONY:fix-gl-deps
fix-gl-deps:
	${CAT} ${.CURDIR}/../../multimedia/gst-plugins1-base/files/base-deps.meson \
		${WRKSRC}/gst-libs/gst/gl/meson.build > \
		${WRKSRC}/gst-libs/gst/gl/meson.build.new
	${MV} ${WRKSRC}/gst-libs/gst/gl/meson.build.new \
		${WRKSRC}/gst-libs/gst/gl/meson.build

pre-configure: fix-gl-deps

.include "../../multimedia/gst-plugins1-base/Makefile.common"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../x11/libdrm/buildlink3.mk"
.endif
.include "../../mk/bsd.pkg.mk"
