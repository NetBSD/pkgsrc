# $NetBSD: buildlink3.mk,v 1.14 2026/11/11 11:55:16 wiz Exp $

BUILDLINK_TREE+=	openmpi

.if !defined(OPENMPI_BUILDLINK3_MK)
OPENMPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openmpi+=	openmpi>=4.1.0
BUILDLINK_ABI_DEPENDS.openmpi?=	openmpi>=4.1.8nb1
BUILDLINK_PKGSRCDIR.openmpi?=	../../parallel/openmpi

BUILDLINK_FILES.openmpi+=	lib/*.mod

.include "../../parallel/hwloc/buildlink3.mk"
.endif # OPENMPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-openmpi
