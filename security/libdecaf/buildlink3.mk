# $NetBSD: buildlink3.mk,v 1.3 2026/05/01 10:56:38 fox Exp $

BUILDLINK_TREE+=	libdecaf

.if !defined(LIBDECAF_BUILDLINK3_MK)
LIBDECAF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdecaf+=	libdecaf>=1.0.0
BUILDLINK_ABI_DEPENDS.libdecaf+=	libdecaf>=1.0.3
BUILDLINK_PKGSRCDIR.libdecaf?=		../../security/libdecaf

.endif # LIBDECAF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdecaf
