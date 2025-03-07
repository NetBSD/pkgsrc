# $NetBSD: buildlink3.mk,v 1.1 2025/03/07 17:26:33 pho Exp $

BUILDLINK_TREE+=	hs-ip

.if !defined(HS_IP_BUILDLINK3_MK)
HS_IP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-ip+=	hs-ip>=1.7.8
BUILDLINK_ABI_DEPENDS.hs-ip+=	hs-ip>=1.7.8
BUILDLINK_PKGSRCDIR.hs-ip?=	../../net/hs-ip

.include "../../converters/hs-aeson/buildlink3.mk"
.include "../../textproc/hs-attoparsec/buildlink3.mk"
.include "../../devel/hs-bytebuild/buildlink3.mk"
.include "../../devel/hs-byteslice/buildlink3.mk"
.include "../../devel/hs-bytesmith/buildlink3.mk"
.include "../../devel/hs-hashable/buildlink3.mk"
.include "../../math/hs-natural-arithmetic/buildlink3.mk"
.include "../../devel/hs-primitive/buildlink3.mk"
.include "../../textproc/hs-text-short/buildlink3.mk"
.include "../../devel/hs-vector/buildlink3.mk"
.include "../../devel/hs-wide-word/buildlink3.mk"
.include "../../devel/hs-word-compat/buildlink3.mk"
.endif	# HS_IP_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-ip
