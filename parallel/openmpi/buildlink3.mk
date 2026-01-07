# $NetBSD: buildlink3.mk,v 1.13 2026/01/07 18:27:38 adam Exp $

BUILDLINK_TREE+=	openmpi

.if !defined(OPENMPI_BUILDLINK3_MK)
OPENMPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openmpi+=	openmpi>=4.1.0
BUILDLINK_PKGSRCDIR.openmpi?=	../../parallel/openmpi

BUILDLINK_FILES.openmpi+=	lib/*.mod

.include "../../parallel/hwloc/buildlink3.mk"
.endif # OPENMPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-openmpi
