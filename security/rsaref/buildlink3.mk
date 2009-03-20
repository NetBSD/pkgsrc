# $NetBSD: buildlink3.mk,v 1.11 2009/03/20 19:25:22 joerg Exp $

BUILDLINK_TREE+=	rsaref

.if !defined(RSAREF_BUILDLINK3_MK)
RSAREF_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.rsaref+=	rsaref>=2.0p3
BUILDLINK_ABI_DEPENDS.rsaref+=	rsaref>=2.0p3nb1
BUILDLINK_PKGSRCDIR.rsaref?=	../../security/rsaref
.endif # RSAREF_BUILDLINK3_MK

BUILDLINK_TREE+=	-rsaref
