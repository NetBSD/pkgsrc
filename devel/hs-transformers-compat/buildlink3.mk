# $NetBSD: buildlink3.mk,v 1.4 2019/12/31 16:09:01 pho Exp $

BUILDLINK_TREE+=	hs-transformers-compat

.if !defined(HS_TRANSFORMERS_COMPAT_BUILDLINK3_MK)
HS_TRANSFORMERS_COMPAT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-transformers-compat+=	hs-transformers-compat>=0.6.5
BUILDLINK_ABI_DEPENDS.hs-transformers-compat+=	hs-transformers-compat>=0.6.5
BUILDLINK_PKGSRCDIR.hs-transformers-compat?=	../../devel/hs-transformers-compat

.include "../../devel/hs-fail/buildlink3.mk"
.include "../../devel/hs-generic-deriving/buildlink3.mk"
.include "../../devel/hs-transformers/buildlink3.mk"
.endif	# HS_TRANSFORMERS_COMPAT_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-transformers-compat
