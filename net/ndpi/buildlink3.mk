# $NetBSD: buildlink3.mk,v 1.3 2020/05/19 12:09:08 nia Exp $

BUILDLINK_TREE+=	ndpi

.if !defined(NDPI_BUILDLINK3_MK)
NDPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ndpi+=	ndpi>=2.8
BUILDLINK_ABI_DEPENDS.ndpi?=	ndpi>=2.8nb1
BUILDLINK_PKGSRCDIR.ndpi?=	../../net/ndpi

.include "../../textproc/json-c/buildlink3.mk"
.endif	# NDPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-ndpi
