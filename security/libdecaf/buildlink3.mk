# $NetBSD: buildlink3.mk,v 1.2 2023/08/14 05:25:10 wiz Exp $

BUILDLINK_TREE+=	libdecaf

.if !defined(LIBDECAF_BUILDLINK3_MK)
LIBDECAF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdecaf+=	libdecaf>=1.0.0
BUILDLINK_ABI_DEPENDS.libdecaf+=	libdecaf>=1.0.2nb1
BUILDLINK_PKGSRCDIR.libdecaf?=		../../security/libdecaf

.endif # LIBDECAF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdecaf
