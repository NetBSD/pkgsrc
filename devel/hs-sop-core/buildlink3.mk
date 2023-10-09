# $NetBSD: buildlink3.mk,v 1.3 2023/10/09 04:54:29 pho Exp $

BUILDLINK_TREE+=	hs-sop-core

.if !defined(HS_SOP_CORE_BUILDLINK3_MK)
HS_SOP_CORE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-sop-core+=	hs-sop-core>=0.5.0
BUILDLINK_ABI_DEPENDS.hs-sop-core+=	hs-sop-core>=0.5.0.2nb2
BUILDLINK_PKGSRCDIR.hs-sop-core?=	../../devel/hs-sop-core
.endif	# HS_SOP_CORE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-sop-core
