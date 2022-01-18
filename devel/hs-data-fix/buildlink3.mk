# $NetBSD: buildlink3.mk,v 1.3 2022/01/18 02:48:06 pho Exp $

BUILDLINK_TREE+=	hs-data-fix

.if !defined(HS_DATA_FIX_BUILDLINK3_MK)
HS_DATA_FIX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-data-fix+=	hs-data-fix>=0.3.1
BUILDLINK_ABI_DEPENDS.hs-data-fix+=	hs-data-fix>=0.3.1nb2
BUILDLINK_PKGSRCDIR.hs-data-fix?=	../../devel/hs-data-fix

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.endif	# HS_DATA_FIX_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-data-fix
