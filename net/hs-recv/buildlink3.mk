# $NetBSD: buildlink3.mk,v 1.7 2025/02/02 13:05:41 pho Exp $

BUILDLINK_TREE+=	hs-recv

.if !defined(HS_RECV_BUILDLINK3_MK)
HS_RECV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-recv+=	hs-recv>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-recv+=	hs-recv>=0.1.0nb3
BUILDLINK_PKGSRCDIR.hs-recv?=	../../net/hs-recv

.include "../../net/hs-network/buildlink3.mk"
.endif	# HS_RECV_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-recv
