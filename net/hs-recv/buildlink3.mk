# $NetBSD: buildlink3.mk,v 1.2 2023/02/07 01:41:02 pho Exp $

BUILDLINK_TREE+=	hs-recv

.if !defined(HS_RECV_BUILDLINK3_MK)
HS_RECV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-recv+=	hs-recv>=0.0.0
BUILDLINK_ABI_DEPENDS.hs-recv+=	hs-recv>=0.0.0nb1
BUILDLINK_PKGSRCDIR.hs-recv?=	../../net/hs-recv

.include "../../net/hs-network/buildlink3.mk"
.endif	# HS_RECV_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-recv
