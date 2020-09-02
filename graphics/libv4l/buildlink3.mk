# $NetBSD: buildlink3.mk,v 1.4 2020/09/02 09:54:33 ryoon Exp $

BUILDLINK_TREE+=	libv4l

.if !defined(LIBV4L_BUILDLINK3_MK)
LIBV4L_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libv4l+=		libv4l>=1.18.1
BUILDLINK_ABI_DEPENDS.libv4l+=		libv4l>=1.18.1
BUILDLINK_PKGSRCDIR.libv4l?=		../../graphics/libv4l
.endif # LIBV4L_BUILDLINK3_MK

BUILDLINK_TREE+=	-libv4l
