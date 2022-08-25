# $NetBSD: buildlink3.mk,v 1.10 2022/08/25 22:09:14 thor Exp $

BUILDLINK_TREE+=	openmpi

.if !defined(OPENMPI_BUILDLINK3_MK)
OPENMPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openmpi+=	openmpi>=1.5.1
BUILDLINK_PKGSRCDIR.openmpi?=	../../wip/openmpi

.endif # OPENMPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-openmpi
