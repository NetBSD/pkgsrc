# $NetBSD: buildlink3.mk,v 1.4 2021/06/23 19:31:49 adam Exp $

BUILDLINK_TREE+=	ndpi

.if !defined(NDPI_BUILDLINK3_MK)
NDPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ndpi+=	ndpi>=3.4
BUILDLINK_ABI_DEPENDS.ndpi+=	ndpi>=3.4
BUILDLINK_PKGSRCDIR.ndpi?=	../../net/ndpi

.include "../../textproc/json-c/buildlink3.mk"
.endif	# NDPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-ndpi
