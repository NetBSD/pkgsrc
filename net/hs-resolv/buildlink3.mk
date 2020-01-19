# $NetBSD: buildlink3.mk,v 1.1 2020/01/19 02:37:03 pho Exp $

BUILDLINK_TREE+=	hs-resolv

.if !defined(HS_RESOLV_BUILDLINK3_MK)
HS_RESOLV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-resolv+=	hs-resolv>=0.1.1
BUILDLINK_ABI_DEPENDS.hs-resolv+=	hs-resolv>=0.1.1.3
BUILDLINK_PKGSRCDIR.hs-resolv?=		../../net/hs-resolv

.include "../../converters/hs-base16-bytestring/buildlink3.mk"
.endif	# HS_RESOLV_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-resolv
