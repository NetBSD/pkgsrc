# $NetBSD: buildlink3.mk,v 1.1 2025/11/07 09:18:43 adam Exp $

BUILDLINK_TREE+=	gcem

.if !defined(GCEM_BUILDLINK3_MK)
GCEM_BUILDLINK3_MK:=

BUILDLINK_DEPMETHOD.gcem?=	build
BUILDLINK_API_DEPENDS.gcem+=	gcem>=1.18.0
BUILDLINK_PKGSRCDIR.gcem?=	../../math/gcem
.endif	# GCEM_BUILDLINK3_MK

BUILDLINK_TREE+=	-gcem
