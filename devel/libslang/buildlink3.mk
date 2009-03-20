# $NetBSD: buildlink3.mk,v 1.18 2009/03/20 19:24:22 joerg Exp $

BUILDLINK_TREE+=	libslang

.if !defined(LIBSLANG_BUILDLINK3_MK)
LIBSLANG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libslang+=	libslang>=1.4.9nb1
BUILDLINK_ABI_DEPENDS.libslang+=	libslang>=1.4.9nb4
BUILDLINK_PKGSRCDIR.libslang?=	../../devel/libslang
.endif # LIBSLANG_BUILDLINK3_MK

BUILDLINK_TREE+=	-libslang
