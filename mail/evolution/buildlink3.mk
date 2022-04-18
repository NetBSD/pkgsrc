# $NetBSD: buildlink3.mk,v 1.101 2022/04/18 19:09:56 adam Exp $

BUILDLINK_TREE+=	evolution

.if !defined(EVOLUTION_BUILDLINK3_MK)
EVOLUTION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evolution+=	evolution>=2.8.0
BUILDLINK_ABI_DEPENDS.evolution+=	evolution>=3.34.1nb15
BUILDLINK_PKGSRCDIR.evolution?=		../../mail/evolution

.include "../../devel/nspr/buildlink3.mk"
.include "../../devel/nss/buildlink3.mk"
.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.endif # EVOLUTION_BUILDLINK3_MK

BUILDLINK_TREE+=	-evolution
