# $NetBSD: buildlink3.mk,v 1.7 2021/12/08 16:02:31 adam Exp $

BUILDLINK_TREE+=	openmpi

.if !defined(OPENMPI_BUILDLINK3_MK)
OPENMPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openmpi+=	openmpi>=1.5.1
BUILDLINK_ABI_DEPENDS.openmpi?=	openmpi>=1.10.7nb7
BUILDLINK_PKGSRCDIR.openmpi?=	../../parallel/openmpi

.include "../../parallel/hwloc/buildlink3.mk"
.endif # OPENMPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-openmpi
