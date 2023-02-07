# $NetBSD: buildlink3.mk,v 1.7 2023/02/07 01:41:11 pho Exp $

BUILDLINK_TREE+=	hs-hxt-charproperties

.if !defined(HS_HXT_CHARPROPERTIES_BUILDLINK3_MK)
HS_HXT_CHARPROPERTIES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hxt-charproperties+=	hs-hxt-charproperties>=9.5.0
BUILDLINK_ABI_DEPENDS.hs-hxt-charproperties+=	hs-hxt-charproperties>=9.5.0.0nb5
BUILDLINK_PKGSRCDIR.hs-hxt-charproperties?=	../../textproc/hs-hxt-charproperties
.endif	# HS_HXT_CHARPROPERTIES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hxt-charproperties
