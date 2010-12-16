# $NetBSD: buildlink3.mk,v 1.2 2010/12/16 21:00:53 asau Exp $

BUILDLINK_TREE+=	openmpi

.if !defined(OPENMPI_BUILDLINK3_MK)
OPENMPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.openmpi+=	openmpi>=1.5.1
BUILDLINK_PKGSRCDIR.openmpi?=	../../parallel/openmpi
.endif # OPENMPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-openmpi
