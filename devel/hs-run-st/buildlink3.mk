# $NetBSD: buildlink3.mk,v 1.3 2026/11/13 14:39:15 pho Exp $

BUILDLINK_TREE+=	hs-run-st

.if !defined(HS_RUN_ST_BUILDLINK3_MK)
HS_RUN_ST_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-run-st+=	hs-run-st>=0.1.3
BUILDLINK_ABI_DEPENDS.hs-run-st+=	hs-run-st>=0.1.3.3nb2
BUILDLINK_PKGSRCDIR.hs-run-st?=		../../devel/hs-run-st

.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../devel/hs-primitive-unlifted/buildlink3.mk"
.endif	# HS_RUN_ST_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-run-st
