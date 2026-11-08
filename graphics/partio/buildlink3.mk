# $NetBSD: buildlink3.mk,v 1.1 2026/11/08 15:01:00 ryoon Exp $

BUILDLINK_TREE+=	partio

.if !defined(PARTIO_BUILDLINK3_MK)
PARTIO_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.partio+=	partio>=1.20.0
BUILDLINK_PKGSRCDIR.partio?=	../../graphics/partio

.endif	# PARTIO_BUILDLINK3_MK

BUILDLINK_TREE+=	-partio
