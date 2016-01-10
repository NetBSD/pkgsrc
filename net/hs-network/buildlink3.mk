# $NetBSD: buildlink3.mk,v 1.11 2016/01/10 11:49:10 szptvlfn Exp $

BUILDLINK_TREE+=	hs-network

.if !defined(HS_NETWORK_BUILDLINK3_MK)
HS_NETWORK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-network+=	hs-network>=2.5.0
BUILDLINK_ABI_DEPENDS.hs-network+=	hs-network>=2.5.0.0nb11
BUILDLINK_PKGSRCDIR.hs-network?=	../../net/hs-network

.include "../../textproc/hs-parsec/buildlink3.mk"
.endif	# HS_NETWORK_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-network
