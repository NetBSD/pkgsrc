# $NetBSD: buildlink3.mk,v 1.8 2009/03/20 19:24:57 joerg Exp $

BUILDLINK_TREE+=	libffm

.if !defined(LIBFFM_BUILDLINK3_MK)
LIBFFM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libffm+=	libffm>=0.28
BUILDLINK_ABI_DEPENDS.libffm?=	libffm>=0.28nb1
BUILDLINK_PKGSRCDIR.libffm?=	../../math/libffm
.endif # LIBFFM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libffm
