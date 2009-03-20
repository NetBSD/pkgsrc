# $NetBSD: buildlink3.mk,v 1.9 2009/03/20 19:25:29 joerg Exp $

BUILDLINK_TREE+=	iso-codes

.if !defined(ISO_CODES_BUILDLINK3_MK)
ISO_CODES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.iso-codes+=	iso-codes>=0.50
BUILDLINK_PKGSRCDIR.iso-codes?=	../../textproc/iso-codes
.endif # ISO_CODES_BUILDLINK3_MK

BUILDLINK_TREE+=	-iso-codes
