# $NetBSD: buildlink3.mk,v 1.74 2018/11/12 03:51:21 ryoon Exp $

BUILDLINK_TREE+=	swfdec

.if !defined(SWFDEC_BUILDLINK3_MK)
SWFDEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.swfdec+=	swfdec>=0.8.2
BUILDLINK_ABI_DEPENDS.swfdec+=	swfdec>=0.8.4nb63
BUILDLINK_PKGSRCDIR.swfdec?=	../../multimedia/swfdec

pkgbase := swfdec
.include "../../mk/pkg-build-options.mk"
.if !empty(PKG_BUILD_OPTIONS.swfdec:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
.endif

.include "../../devel/liboil/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # SWFDEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-swfdec
