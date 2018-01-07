# $NetBSD: buildlink3.mk,v 1.9 2018/01/07 13:04:34 rillig Exp $

BUILDLINK_TREE+=	libunicode

.if !defined(LIBUNICODE_BUILDLINK3_MK)
LIBUNICODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libunicode+=	libunicode>=0.4
BUILDLINK_ABI_DEPENDS.libunicode+=	libunicode>=0.4nb1
BUILDLINK_PKGSRCDIR.libunicode?=	../../textproc/libunicode
.endif # LIBUNICODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-libunicode
