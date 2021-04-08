# $NetBSD: buildlink3.mk,v 1.19 2021/04/08 21:08:40 adam Exp $

BUILDLINK_TREE+=	cairomm

.if !defined(CAIROMM_BUILDLINK3_MK)
CAIROMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cairomm+=	cairomm>=1.2.2
BUILDLINK_ABI_DEPENDS.cairomm+=	cairomm>=1.12.2nb5
BUILDLINK_PKGSRCDIR.cairomm?=	../../graphics/cairomm

.include "../../devel/libsigc++/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.endif # CAIROMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-cairomm
