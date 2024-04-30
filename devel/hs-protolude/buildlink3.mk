# $NetBSD: buildlink3.mk,v 1.8 2024/04/30 13:38:14 pho Exp $

BUILDLINK_TREE+=	hs-protolude

.if !defined(HS_PROTOLUDE_BUILDLINK3_MK)
HS_PROTOLUDE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-protolude+=	hs-protolude>=0.3.4
BUILDLINK_ABI_DEPENDS.hs-protolude+=	hs-protolude>=0.3.4
BUILDLINK_PKGSRCDIR.hs-protolude?=	../../devel/hs-protolude

.include "../../devel/hs-async/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../devel/hs-mtl-compat/buildlink3.mk"
.include "../../devel/hs-transformers-compat/buildlink3.mk"
.endif	# HS_PROTOLUDE_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-protolude
