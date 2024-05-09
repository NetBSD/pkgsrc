# $NetBSD: buildlink3.mk,v 1.14 2024/05/09 01:32:28 pho Exp $

BUILDLINK_TREE+=	hs-extra

.if !defined(HS_EXTRA_BUILDLINK3_MK)
HS_EXTRA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-extra+=	hs-extra>=1.7.14
BUILDLINK_ABI_DEPENDS.hs-extra+=	hs-extra>=1.7.14nb2
BUILDLINK_PKGSRCDIR.hs-extra?=		../../misc/hs-extra

.include "../../time/hs-clock/buildlink3.mk"
.endif	# HS_EXTRA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-extra
