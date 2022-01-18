# $NetBSD: buildlink3.mk,v 1.3 2022/01/18 02:48:19 pho Exp $

BUILDLINK_TREE+=	hs-iproute

.if !defined(HS_IPROUTE_BUILDLINK3_MK)
HS_IPROUTE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-iproute+=	hs-iproute>=1.7.11
BUILDLINK_ABI_DEPENDS.hs-iproute+=	hs-iproute>=1.7.11nb2
BUILDLINK_PKGSRCDIR.hs-iproute?=	../../net/hs-iproute

.include "../../textproc/hs-appar/buildlink3.mk"
.include "../../sysutils/hs-byteorder/buildlink3.mk"
.include "../../net/hs-network/buildlink3.mk"
.endif	# HS_IPROUTE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-iproute
