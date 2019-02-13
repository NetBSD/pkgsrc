# $NetBSD: buildlink3.mk,v 1.5 2019/02/13 15:16:00 tnn Exp $

BUILDLINK_TREE+=	qrencode

.if !defined(QRENCODE_BUILDLINK3_MK)
QRENCODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qrencode+=	qrencode>=4.0.2
BUILDLINK_PKGSRCDIR.qrencode?=		../../converters/qrencode
.endif # QRENCODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qrencode
