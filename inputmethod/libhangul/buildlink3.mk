# $NetBSD: buildlink3.mk,v 1.4 2011/11/10 10:40:11 obache Exp $

BUILDLINK_TREE+=	libhangul

.if !defined(LIBHANGUL_BUILDLINK3_MK)
LIBHANGUL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libhangul+=	libhangul>=0.0.4
BUILDLINK_ABI_DEPENDS.libhangul+=	libhangul>=0.1.0
BUILDLINK_PKGSRCDIR.libhangul?=	../../inputmethod/libhangul
.endif # LIBHANGUL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libhangul
