# $NetBSD: buildlink3.mk,v 1.8 2012/09/07 19:16:41 adam Exp $

BUILDLINK_TREE+=	cairomm

.if !defined(CAIROMM_BUILDLINK3_MK)
CAIROMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cairomm+=	cairomm>=1.2.2
BUILDLINK_ABI_DEPENDS.cairomm+=	cairomm>=1.10.0nb2
BUILDLINK_PKGSRCDIR.cairomm?=	../../graphics/cairomm

.include "../../graphics/cairo/buildlink3.mk"
.endif # CAIROMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-cairomm
