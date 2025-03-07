# $NetBSD: buildlink3.mk,v 1.1 2025/03/07 14:04:19 pho Exp $

BUILDLINK_TREE+=	hs-hxt-relaxng

.if !defined(HS_HXT_RELAXNG_BUILDLINK3_MK)
HS_HXT_RELAXNG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-hxt-relaxng+=	hs-hxt-relaxng>=9.1.5
BUILDLINK_ABI_DEPENDS.hs-hxt-relaxng+=	hs-hxt-relaxng>=9.1.5.5
BUILDLINK_PKGSRCDIR.hs-hxt-relaxng?=	../../textproc/hs-hxt-relaxng

.include "../../textproc/hs-hxt/buildlink3.mk"
.include "../../textproc/hs-hxt-charproperties/buildlink3.mk"
.include "../../textproc/hs-hxt-regex-xmlschema/buildlink3.mk"
.include "../../net/hs-network-uri/buildlink3.mk"
.endif	# HS_HXT_RELAXNG_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-hxt-relaxng
