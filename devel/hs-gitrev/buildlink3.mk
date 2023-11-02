# $NetBSD: buildlink3.mk,v 1.5 2023/11/02 06:36:33 pho Exp $

BUILDLINK_TREE+=	hs-gitrev

.if !defined(HS_GITREV_BUILDLINK3_MK)
HS_GITREV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-gitrev+=	hs-gitrev>=1.3.1
BUILDLINK_ABI_DEPENDS.hs-gitrev+=	hs-gitrev>=1.3.1nb4
BUILDLINK_PKGSRCDIR.hs-gitrev?=		../../devel/hs-gitrev

.include "../../devel/hs-base-compat/buildlink3.mk"
.endif	# HS_GITREV_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-gitrev
