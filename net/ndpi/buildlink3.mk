# $NetBSD: buildlink3.mk,v 1.2 2019/07/12 09:30:34 adam Exp $

BUILDLINK_TREE+=	ndpi

.if !defined(NDPI_BUILDLINK3_MK)
NDPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ndpi+=	ndpi>=2.8
BUILDLINK_PKGSRCDIR.ndpi?=	../../net/ndpi

.include "../../textproc/json-c/buildlink3.mk"
.endif	# NDPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-ndpi
