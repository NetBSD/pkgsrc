# $NetBSD: buildlink3.mk,v 1.6 2024/05/09 01:31:57 pho Exp $

BUILDLINK_TREE+=	hs-gitrev

.if !defined(HS_GITREV_BUILDLINK3_MK)
HS_GITREV_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-gitrev+=	hs-gitrev>=1.3.1
BUILDLINK_ABI_DEPENDS.hs-gitrev+=	hs-gitrev>=1.3.1nb5
BUILDLINK_PKGSRCDIR.hs-gitrev?=		../../devel/hs-gitrev

.include "../../devel/hs-base-compat/buildlink3.mk"
.endif	# HS_GITREV_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-gitrev
