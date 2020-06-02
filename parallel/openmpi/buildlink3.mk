# $NetBSD: buildlink3.mk,v 1.4 2020/06/02 08:22:54 adam Exp $

BUILDLINK_TREE+=	openmpi

.if !defined(OPENMPI_BUILDLINK3_MK)
OPENMPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openmpi+=	openmpi>=1.5.1
BUILDLINK_ABI_DEPENDS.openmpi?=	openmpi>=1.10.7nb3
BUILDLINK_PKGSRCDIR.openmpi?=	../../parallel/openmpi

.include "../../parallel/hwloc/buildlink3.mk"
.endif # OPENMPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-openmpi
