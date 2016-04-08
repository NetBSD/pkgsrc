# $NetBSD: buildlink3.mk,v 1.1 2016/04/08 16:51:23 adam Exp $

BUILDLINK_TREE+=	ndpi

.if !defined(NDPI_BUILDLINK3_MK)
NDPI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ndpi+=	ndpi>=1.7
BUILDLINK_PKGSRCDIR.ndpi?=	../../net/ndpi

.include "../../textproc/json-c/buildlink3.mk"
.endif	# NDPI_BUILDLINK3_MK

BUILDLINK_TREE+=	-ndpi
