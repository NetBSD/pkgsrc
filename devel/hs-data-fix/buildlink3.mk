# $NetBSD: buildlink3.mk,v 1.6 2022/02/26 03:57:52 pho Exp $

BUILDLINK_TREE+=	hs-data-fix

.if !defined(HS_DATA_FIX_BUILDLINK3_MK)
HS_DATA_FIX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-data-fix+=	hs-data-fix>=0.3.2
BUILDLINK_ABI_DEPENDS.hs-data-fix+=	hs-data-fix>=0.3.2nb2
BUILDLINK_PKGSRCDIR.hs-data-fix?=	../../devel/hs-data-fix

.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.endif	# HS_DATA_FIX_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-data-fix
