# $NetBSD: buildlink3.mk,v 1.3 2024/05/06 09:58:13 pho Exp $

BUILDLINK_TREE+=	hs-hfsevents

.if !defined(HS_HFSEVENTS_BUILDLINK3_MK)
HS_HFSEVENTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hfsevents+=	hs-hfsevents>=0.1.7
BUILDLINK_ABI_DEPENDS.hs-hfsevents+=	hs-hfsevents>=0.1.7
BUILDLINK_PKGSRCDIR.hs-hfsevents?=	../../devel/hs-hfsevents

.include "../../devel/hs-cereal/buildlink3.mk"
.endif	# HS_HFSEVENTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hfsevents
