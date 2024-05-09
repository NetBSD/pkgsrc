# $NetBSD: buildlink3.mk,v 1.3 2024/05/09 01:32:34 pho Exp $

BUILDLINK_TREE+=	hs-skein

.if !defined(HS_SKEIN_BUILDLINK3_MK)
HS_SKEIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-skein+=	hs-skein>=1.0.9
BUILDLINK_ABI_DEPENDS.hs-skein+=	hs-skein>=1.0.9.4nb2
BUILDLINK_PKGSRCDIR.hs-skein?=		../../security/hs-skein

.include "../../devel/hs-cereal/buildlink3.mk"
.include "../../security/hs-crypto-api/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.endif	# HS_SKEIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-skein
