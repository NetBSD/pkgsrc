# $NetBSD: buildlink3.mk,v 1.11 2009/03/20 19:24:20 joerg Exp $

BUILDLINK_TREE+=	libmm

.if !defined(LIBMM_BUILDLINK3_MK)
LIBMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libmm+=	libmm>=1.4.0
BUILDLINK_PKGSRCDIR.libmm?=	../../devel/libmm
.endif # LIBMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libmm
