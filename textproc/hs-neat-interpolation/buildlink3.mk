# $NetBSD: buildlink3.mk,v 1.4 2025/08/13 11:07:33 pho Exp $

BUILDLINK_TREE+=	hs-neat-interpolation

.if !defined(HS_NEAT_INTERPOLATION_BUILDLINK3_MK)
HS_NEAT_INTERPOLATION_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hs-neat-interpolation+=	hs-neat-interpolation>=0.5.1
BUILDLINK_ABI_DEPENDS.hs-neat-interpolation+=	hs-neat-interpolation>=0.5.1.4nb3
BUILDLINK_PKGSRCDIR.hs-neat-interpolation?=	../../textproc/hs-neat-interpolation

.include "../../textproc/hs-megaparsec/buildlink3.mk"
.endif	# HS_NEAT_INTERPOLATION_BUILDLINK3_MK

BUILDLINK_TREE+=	-hs-neat-interpolation
