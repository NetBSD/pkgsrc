# $NetBSD: buildlink3.mk,v 1.3 2009/03/20 19:24:47 joerg Exp $

BUILDLINK_TREE+=	libhangul

.if !defined(LIBHANGUL_BUILDLINK3_MK)
LIBHANGUL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libhangul+=	libhangul>=0.0.4
BUILDLINK_PKGSRCDIR.libhangul?=	../../inputmethod/libhangul
.endif # LIBHANGUL_BUILDLINK3_MK

BUILDLINK_TREE+=	-libhangul
