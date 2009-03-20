# $NetBSD: buildlink3.mk,v 1.2 2009/03/20 19:24:37 joerg Exp $

BUILDLINK_TREE+=	cairomm

.if !defined(CAIROMM_BUILDLINK3_MK)
CAIROMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cairomm+=	cairomm>=1.2.2
BUILDLINK_PKGSRCDIR.cairomm?=	../../graphics/cairomm

.include "../../graphics/cairo/buildlink3.mk"
.endif # CAIROMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-cairomm
