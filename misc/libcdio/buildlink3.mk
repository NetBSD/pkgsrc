# $NetBSD: buildlink3.mk,v 1.15 2022/06/28 11:34:48 wiz Exp $

BUILDLINK_TREE+=	libcdio

.if !defined(LIBCDIO_BUILDLINK3_MK)
LIBCDIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcdio+=	libcdio>=0.93
BUILDLINK_ABI_DEPENDS.libcdio+=	libcdio>=2.1.0nb5
BUILDLINK_PKGSRCDIR.libcdio?=	../../misc/libcdio
.endif # LIBCDIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcdio
