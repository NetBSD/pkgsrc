# $NetBSD: buildlink3.mk,v 1.2 2025/03/08 05:13:50 pho Exp $

BUILDLINK_TREE+=	hs-hpack

.if !defined(HS_HPACK_BUILDLINK3_MK)
HS_HPACK_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hpack+=	hs-hpack>=0.38.0
BUILDLINK_ABI_DEPENDS.hs-hpack+=	hs-hpack>=0.38.0nb1
BUILDLINK_PKGSRCDIR.hs-hpack?=		../../devel/hs-hpack

.include "../../textproc/hs-Glob/buildlink3.mk"
.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../math/hs-bifunctors/buildlink3.mk"
.include "../../security/hs-crypton/buildlink3.mk"
.include "../../www/hs-http-client/buildlink3.mk"
.include "../../www/hs-http-client-tls/buildlink3.mk"
.include "../../www/hs-http-types/buildlink3.mk"
.include "../../devel/hs-infer-license/buildlink3.mk"
.include "../../math/hs-scientific/buildlink3.mk"
.include "../../devel/hs-unordered-containers/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../textproc/hs-yaml/buildlink3.mk"
.endif	# HS_HPACK_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hpack
