# $NetBSD: buildlink3.mk,v 1.4 2018/01/07 13:03:58 rillig Exp $

BUILDLINK_TREE+=	qrencode

.if !defined(QRENCODE_BUILDLINK3_MK)
QRENCODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qrencode+=	qrencode>=3.4.1
BUILDLINK_PKGSRCDIR.qrencode?=		../../converters/qrencode
.endif # QRENCODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qrencode
