# $NetBSD: buildlink3.mk,v 1.3 2025/03/05 03:40:00 pho Exp $

BUILDLINK_TREE+=	hs-neat-interpolation

.if !defined(HS_NEAT_INTERPOLATION_BUILDLINK3_MK)
HS_NEAT_INTERPOLATION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-neat-interpolation+=	hs-neat-interpolation>=0.5.1
BUILDLINK_ABI_DEPENDS.hs-neat-interpolation+=	hs-neat-interpolation>=0.5.1.4nb2
BUILDLINK_PKGSRCDIR.hs-neat-interpolation?=	../../textproc/hs-neat-interpolation

.include "../../textproc/hs-megaparsec/buildlink3.mk"
.endif	# HS_NEAT_INTERPOLATION_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-neat-interpolation
