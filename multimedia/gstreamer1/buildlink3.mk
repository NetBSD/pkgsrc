# $NetBSD: buildlink3.mk,v 1.7 2022/11/25 14:20:45 nia Exp $

BUILDLINK_TREE+=	gstreamer1

.if !defined(GSTREAMER1_BUILDLINK3_MK)
GSTREAMER1_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gstreamer1+=	gstreamer1>=1.18.4
BUILDLINK_ABI_DEPENDS.gstreamer1?=	gstreamer1>=1.20.2nb2
BUILDLINK_PKGSRCDIR.gstreamer1?=	../../multimedia/gstreamer1
BUILDLINK_INCDIRS.gstreamer1?=		include/gstreamer-1.0

.include "../../devel/glib2/buildlink3.mk"
.endif # GSTREAMER1_BUILDLINK3_MK

BUILDLINK_TREE+=	-gstreamer1
