# $NetBSD: buildlink3.mk,v 1.4 2023/10/27 11:03:52 pho Exp $

BUILDLINK_TREE+=	hs-recv

.if !defined(HS_RECV_BUILDLINK3_MK)
HS_RECV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-recv+=	hs-recv>=0.1.0
BUILDLINK_ABI_DEPENDS.hs-recv+=	hs-recv>=0.1.0
BUILDLINK_PKGSRCDIR.hs-recv?=	../../net/hs-recv

.include "../../net/hs-network/buildlink3.mk"
.endif	# HS_RECV_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-recv
