# $NetBSD: buildlink3.mk,v 1.3 2012/12/16 14:23:07 ryoon Exp $

BUILDLINK_TREE+=	qrencode

.if !defined(QRENCODE_BUILDLINK3_MK)
QRENCODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.qrencode+=	qrencode>=3.4.1
BUILDLINK_PKGSRCDIR.qrencode?=	../../converters/qrencode
.endif # QRENCODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-qrencode
