# $NetBSD: buildlink3.mk,v 1.5 2025/03/05 03:39:50 pho Exp $

BUILDLINK_TREE+=	hs-skein

.if !defined(HS_SKEIN_BUILDLINK3_MK)
HS_SKEIN_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-skein+=	hs-skein>=1.0.9
BUILDLINK_ABI_DEPENDS.hs-skein+=	hs-skein>=1.0.9.4nb4
BUILDLINK_PKGSRCDIR.hs-skein?=		../../security/hs-skein

.include "../../devel/hs-cereal/buildlink3.mk"
.include "../../security/hs-crypto-api/buildlink3.mk"
.include "../../devel/hs-tagged/buildlink3.mk"
.endif	# HS_SKEIN_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-skein
