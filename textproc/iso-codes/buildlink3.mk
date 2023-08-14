# $NetBSD: buildlink3.mk,v 1.11 2023/08/14 05:25:22 wiz Exp $

BUILDLINK_TREE+=	iso-codes

.if !defined(ISO_CODES_BUILDLINK3_MK)
ISO_CODES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.iso-codes+=	iso-codes>=0.50
BUILDLINK_ABI_DEPENDS.iso-codes?=		iso-codes>=4.11.0nb1
BUILDLINK_PKGSRCDIR.iso-codes?=		../../textproc/iso-codes
.endif # ISO_CODES_BUILDLINK3_MK

BUILDLINK_TREE+=	-iso-codes
