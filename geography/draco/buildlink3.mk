# $NetBSD: buildlink3.mk,v 1.1 2025/06/09 20:40:21 wiz Exp $

BUILDLINK_TREE+=	draco

.if !defined(DRACO_BUILDLINK3_MK)
DRACO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.draco+=	draco>=1.5.7
BUILDLINK_PKGSRCDIR.draco?=	../../geography/draco
.endif	# DRACO_BUILDLINK3_MK

BUILDLINK_TREE+=	-draco
