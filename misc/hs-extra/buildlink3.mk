# $NetBSD: buildlink3.mk,v 1.1 2020/01/03 06:04:34 pho Exp $

BUILDLINK_TREE+=	hs-extra

.if !defined(HS_EXTRA_BUILDLINK3_MK)
HS_EXTRA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-extra+=	hs-extra>=1.6.18
BUILDLINK_ABI_DEPENDS.hs-extra+=	hs-extra>=1.6.18
BUILDLINK_PKGSRCDIR.hs-extra?=	../../misc/hs-extra

.include "../../time/hs-clock/buildlink3.mk"
.include "../../math/hs-semigroups/buildlink3.mk"
.endif	# HS_EXTRA_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-extra
