# $NetBSD: buildlink3.mk,v 1.16 2025/12/26 11:12:06 adam Exp $

BUILDLINK_TREE+=	libcdio

.if !defined(LIBCDIO_BUILDLINK3_MK)
LIBCDIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcdio+=	libcdio>=0.93
BUILDLINK_ABI_DEPENDS.libcdio+=	libcdio>=2.3.0
BUILDLINK_PKGSRCDIR.libcdio?=	../../misc/libcdio
.endif # LIBCDIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcdio
