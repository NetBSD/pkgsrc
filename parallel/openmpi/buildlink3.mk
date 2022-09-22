# $NetBSD: buildlink3.mk,v 1.12 2022/09/22 16:47:27 thor Exp $

BUILDLINK_TREE+=	openmpi

.if !defined(OPENMPI_BUILDLINK3_MK)
OPENMPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openmpi+=	openmpi>=1.5.1
BUILDLINK_PKGSRCDIR.openmpi?=	../../parallel/openmpi

BUILDLINK_FILES.openmpi+=	lib/*.mod

.endif # OPENMPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-openmpi
