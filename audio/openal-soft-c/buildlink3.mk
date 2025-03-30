# $NetBSD: buildlink3.mk,v 1.1 2025/03/30 09:32:07 nia Exp $

BUILDLINK_TREE+=	openal-soft

.if !defined(OPENAL_SOFT_BUILDLINK3_MK)
OPENAL_SOFT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openal-soft+=	openal-soft>=1.5.304<1.20.0
BUILDLINK_PKGSRCDIR.openal-soft?=	../../audio/openal-soft-c
.endif	# OPENAL_SOFT_BUILDLINK3_MK

BUILDLINK_TREE+=	-openal-soft
