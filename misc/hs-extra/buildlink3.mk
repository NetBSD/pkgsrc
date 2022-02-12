# $NetBSD: buildlink3.mk,v 1.6 2022/02/12 08:50:45 pho Exp $

BUILDLINK_TREE+=	hs-extra

.if !defined(HS_EXTRA_BUILDLINK3_MK)
HS_EXTRA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-extra+=	hs-extra>=1.7.10
BUILDLINK_ABI_DEPENDS.hs-extra+=	hs-extra>=1.7.10nb1
BUILDLINK_PKGSRCDIR.hs-extra?=		../../misc/hs-extra

.include "../../time/hs-clock/buildlink3.mk"
.endif	# HS_EXTRA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-extra
