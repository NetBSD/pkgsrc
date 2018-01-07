# $NetBSD: buildlink3.mk,v 1.10 2018/01/07 13:04:33 rillig Exp $

BUILDLINK_TREE+=	iso-codes

.if !defined(ISO_CODES_BUILDLINK3_MK)
ISO_CODES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.iso-codes+=	iso-codes>=0.50
BUILDLINK_PKGSRCDIR.iso-codes?=		../../textproc/iso-codes
.endif # ISO_CODES_BUILDLINK3_MK

BUILDLINK_TREE+=	-iso-codes
