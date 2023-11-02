# $NetBSD: buildlink3.mk,v 1.7 2023/11/02 06:36:52 pho Exp $

BUILDLINK_TREE+=	hs-protolude

.if !defined(HS_PROTOLUDE_BUILDLINK3_MK)
HS_PROTOLUDE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-protolude+=	hs-protolude>=0.3.3
BUILDLINK_ABI_DEPENDS.hs-protolude+=	hs-protolude>=0.3.3nb1
BUILDLINK_PKGSRCDIR.hs-protolude?=	../../devel/hs-protolude

.include "../../devel/hs-async/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-mtl-compat/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.endif	# HS_PROTOLUDE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-protolude
