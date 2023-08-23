# $NetBSD: buildlink3.mk,v 1.1 2023/08/23 18:47:46 charlotte Exp $

BUILDLINK_TREE+=	libopenmpt

.if !defined(LIBOPENMPT_BUILDLINK3_MK)
LIBOPENMPT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libopenmpt+=	libopenmpt>=0.7.2
BUILDLINK_ABI_DEPENDS.libopenmpt+=	libopenmpt>=0.7.2
BUILDLINK_PKGSRCDIR.libopenmpt?=	../../audio/libopenmpt

.endif # LIBOPENMPT_BUILDLINK3_MK

BUILDLINK_TREE+=	-libopenmpt
