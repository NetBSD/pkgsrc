# $NetBSD: buildlink3.mk,v 1.5 2022/02/12 08:50:46 pho Exp $

BUILDLINK_TREE+=	hs-resolv

.if !defined(HS_RESOLV_BUILDLINK3_MK)
HS_RESOLV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-resolv+=	hs-resolv>=0.1.2
BUILDLINK_ABI_DEPENDS.hs-resolv+=	hs-resolv>=0.1.2.0nb3
BUILDLINK_PKGSRCDIR.hs-resolv?=		../../net/hs-resolv

.include "../../converters/hs-base16-bytestring/buildlink3.mk"
.endif	# HS_RESOLV_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-resolv
