# $NetBSD: buildlink3.mk,v 1.1 2019/08/11 16:47:52 fox Exp $

BUILDLINK_TREE+=	libdecaf

.if !defined(LIBDECAF_BUILDLINK3_MK)
LIBDECAF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libdecaf+=	libdecaf>=1.0.0
BUILDLINK_ABI_DEPENDS.libdecaf+=	libdecaf>=1.0.0
BUILDLINK_PKGSRCDIR.libdecaf?=		../../security/libdecaf

.endif # LIBDECAF_BUILDLINK3_MK

BUILDLINK_TREE+=	-libdecaf
