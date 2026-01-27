# $NetBSD: buildlink3.mk,v 1.26 2026/01/27 08:39:36 wiz Exp $

BUILDLINK_TREE+=	cairomm

.if !defined(CAIROMM_BUILDLINK3_MK)
CAIROMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cairomm+=	cairomm>=1.2.2
BUILDLINK_ABI_DEPENDS.cairomm+=	cairomm>=1.14.5nb5
BUILDLINK_PKGSRCDIR.cairomm?=	../../graphics/cairomm

.include "../../devel/libsigc++/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.endif # CAIROMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-cairomm
