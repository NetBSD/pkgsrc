# $NetBSD: buildlink3.mk,v 1.106 2023/01/03 17:36:29 wiz Exp $

BUILDLINK_TREE+=	evolution

.if !defined(EVOLUTION_BUILDLINK3_MK)
EVOLUTION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.evolution+=	evolution>=2.8.0
BUILDLINK_ABI_DEPENDS.evolution+=	evolution>=3.34.1nb20
BUILDLINK_PKGSRCDIR.evolution?=		../../mail/evolution

.include "../../mail/evolution-data-server/buildlink3.mk"
.include "../../audio/libcanberra/buildlink3.mk"
.endif # EVOLUTION_BUILDLINK3_MK

BUILDLINK_TREE+=	-evolution
