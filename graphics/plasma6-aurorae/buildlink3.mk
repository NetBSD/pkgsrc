# $NetBSD: buildlink3.mk,v 1.2 2025/12/31 04:08:47 markd Exp $

BUILDLINK_TREE+=	plasma6-aurorae

.if !defined(PLASMA6_AURORAE_BUILDLINK3_MK)
PLASMA6_AURORAE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.plasma6-aurorae+=	plasma6-aurorae>=6.5.2
BUILDLINK_PKGSRCDIR.plasma6-aurorae?=	../../graphics/plasma6-aurorae

.endif	# PLASMA6_AURORAE_BUILDLINK3_MK

BUILDLINK_TREE+=	-plasma6-aurorae
