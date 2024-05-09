# $NetBSD: buildlink3.mk,v 1.5 2024/05/09 01:31:43 pho Exp $

BUILDLINK_TREE+=	hs-HUnit

.if !defined(HS_HUNIT_BUILDLINK3_MK)
HS_HUNIT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-HUnit+=	hs-HUnit>=1.6.2
BUILDLINK_ABI_DEPENDS.hs-HUnit+=	hs-HUnit>=1.6.2.0nb4
BUILDLINK_PKGSRCDIR.hs-HUnit?=		../../devel/hs-HUnit

.include "../../devel/hs-call-stack/buildlink3.mk"
.endif	# HS_HUNIT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-HUnit
