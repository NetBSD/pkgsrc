# $NetBSD: buildlink3.mk,v 1.14 2008/10/31 12:44:51 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SWFDEC_BUILDLINK3_MK:=	${SWFDEC_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	swfdec
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nswfdec}
BUILDLINK_PACKAGES+=	swfdec
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}swfdec

.if ${SWFDEC_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.swfdec+=	swfdec>=0.8.2
BUILDLINK_PKGSRCDIR.swfdec?=	../../multimedia/swfdec
.endif	# SWFDEC_BUILDLINK3_MK

.include "../../devel/liboil/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
