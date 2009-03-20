# $NetBSD: buildlink3.mk,v 1.15 2009/03/20 19:25:05 joerg Exp $

BUILDLINK_TREE+=	swfdec

.if !defined(SWFDEC_BUILDLINK3_MK)
SWFDEC_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.swfdec+=	swfdec>=0.8.2
BUILDLINK_PKGSRCDIR.swfdec?=	../../multimedia/swfdec

.include "../../devel/liboil/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.endif # SWFDEC_BUILDLINK3_MK

BUILDLINK_TREE+=	-swfdec
