# $NetBSD: buildlink3.mk,v 1.3 2022/01/18 02:48:20 pho Exp $

BUILDLINK_TREE+=	hs-socks

.if !defined(HS_SOCKS_BUILDLINK3_MK)
HS_SOCKS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-socks+=	hs-socks>=0.6.1
BUILDLINK_ABI_DEPENDS.hs-socks+=	hs-socks>=0.6.1nb2
BUILDLINK_PKGSRCDIR.hs-socks?=		../../net/hs-socks

.include "../../devel/hs-basement/buildlink3.mk"
.include "../../devel/hs-cereal/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.endif	# HS_SOCKS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-socks
