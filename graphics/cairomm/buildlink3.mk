# $NetBSD: buildlink3.mk,v 1.3 2010/06/13 22:44:27 wiz Exp $

BUILDLINK_TREE+=	cairomm

.if !defined(CAIROMM_BUILDLINK3_MK)
CAIROMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cairomm+=	cairomm>=1.2.2
BUILDLINK_ABI_DEPENDS.cairomm?=	cairomm>=1.8.4nb1
BUILDLINK_PKGSRCDIR.cairomm?=	../../graphics/cairomm

.include "../../graphics/cairo/buildlink3.mk"
.endif # CAIROMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-cairomm
