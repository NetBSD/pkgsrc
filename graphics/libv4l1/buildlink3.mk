# $NetBSD: buildlink3.mk,v 1.1 2020/08/29 22:18:41 ryoon Exp $

BUILDLINK_TREE+=	libv4l

.if !defined(LIBV4L_BUILDLINK3_MK)
LIBV4L_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libv4l+=		libv4l>=1.18.1
BUILDLINK_ABI_DEPENDS.libv4l+=		libv4l>=1.18.1
BUILDLINK_PKGSRCDIR.libv4l?=		../../graphics/libv4l1
.endif # LIBV4L_BUILDLINK3_MK

BUILDLINK_TREE+=	-libv4l
