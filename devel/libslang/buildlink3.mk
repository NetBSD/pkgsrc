# $NetBSD: buildlink3.mk,v 1.19 2018/01/07 13:04:06 rillig Exp $

BUILDLINK_TREE+=	libslang

.if !defined(LIBSLANG_BUILDLINK3_MK)
LIBSLANG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libslang+=	libslang>=1.4.9nb1
BUILDLINK_ABI_DEPENDS.libslang+=	libslang>=1.4.9nb4
BUILDLINK_PKGSRCDIR.libslang?=		../../devel/libslang
.endif # LIBSLANG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libslang
