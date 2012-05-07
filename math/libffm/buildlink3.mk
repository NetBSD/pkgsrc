# $NetBSD: buildlink3.mk,v 1.9 2012/05/07 01:53:46 dholland Exp $

BUILDLINK_TREE+=	libffm

.if !defined(LIBFFM_BUILDLINK3_MK)
LIBFFM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libffm+=	libffm>=0.28
BUILDLINK_ABI_DEPENDS.libffm+=	libffm>=0.28nb1
BUILDLINK_PKGSRCDIR.libffm?=	../../math/libffm
.endif # LIBFFM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libffm
