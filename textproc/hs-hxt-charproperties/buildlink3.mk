# $NetBSD: buildlink3.mk,v 1.4 2022/01/18 02:48:26 pho Exp $

BUILDLINK_TREE+=	hs-hxt-charproperties

.if !defined(HS_HXT_CHARPROPERTIES_BUILDLINK3_MK)
HS_HXT_CHARPROPERTIES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hxt-charproperties+=	hs-hxt-charproperties>=9.5.0
BUILDLINK_ABI_DEPENDS.hs-hxt-charproperties+=	hs-hxt-charproperties>=9.5.0.0nb2
BUILDLINK_PKGSRCDIR.hs-hxt-charproperties?=	../../textproc/hs-hxt-charproperties
.endif	# HS_HXT_CHARPROPERTIES_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hxt-charproperties
