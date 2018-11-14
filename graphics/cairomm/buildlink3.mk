# $NetBSD: buildlink3.mk,v 1.17 2018/11/14 22:21:35 kleink Exp $

BUILDLINK_TREE+=	cairomm

.if !defined(CAIROMM_BUILDLINK3_MK)
CAIROMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.cairomm+=	cairomm>=1.2.2
BUILDLINK_ABI_DEPENDS.cairomm+=	cairomm>=1.12.2nb3
BUILDLINK_PKGSRCDIR.cairomm?=	../../graphics/cairomm

.include "../../graphics/cairo/buildlink3.mk"
.endif # CAIROMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-cairomm
