# $NetBSD: buildlink3.mk,v 1.1 2025/12/23 10:23:07 markd Exp $

BUILDLINK_TREE+=	plasma6-breeze

.if !defined(PLASMA6_BREEZE_BUILDLINK3_MK)
PLASMA6_BREEZE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.plasma6-breeze+=	plasma6-breeze>=6.5.2
BUILDLINK_PKGSRCDIR.plasma6-breeze?=	../../graphics/plasma6-breeze

.endif	# PLASMA6_BREEZE_BUILDLINK3_MK

BUILDLINK_TREE+=	-plasma6-breeze
