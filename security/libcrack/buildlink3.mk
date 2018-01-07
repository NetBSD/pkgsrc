# $NetBSD: buildlink3.mk,v 1.12 2018/01/07 13:04:29 rillig Exp $

BUILDLINK_TREE+=	libcrack

.if !defined(LIBCRACK_BUILDLINK3_MK)
LIBCRACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libcrack+=	libcrack>=2.7
BUILDLINK_ABI_DEPENDS.libcrack+=	libcrack>=2.7nb1
BUILDLINK_PKGSRCDIR.libcrack?=		../../security/libcrack
.endif # LIBCRACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-libcrack
