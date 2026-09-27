# $NetBSD: buildlink3.mk,v 1.12 2026/09/27 11:37:51 tnn Exp $

BUILDLINK_TREE+=	gstreamer1

.if !defined(GSTREAMER1_BUILDLINK3_MK)
GSTREAMER1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gstreamer1+=	gstreamer1>=1.18.4
BUILDLINK_ABI_DEPENDS.gstreamer1+=	gstreamer1>=1.28.6nb2
BUILDLINK_PKGSRCDIR.gstreamer1?=	../../multimedia/gstreamer1
BUILDLINK_INCDIRS.gstreamer1?=		include/gstreamer-1.0

.include "../../devel/glib2/buildlink3.mk"
.endif # GSTREAMER1_BUILDLINK3_MK

BUILDLINK_TREE+=	-gstreamer1
