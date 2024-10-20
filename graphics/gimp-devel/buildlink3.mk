# $NetBSD: buildlink3.mk,v 1.12 2024/10/20 14:03:55 wiz Exp $

BUILDLINK_TREE+=	gimp-devel

.if !defined(GIMP_DEVEL_BUILDLINK3_MK)
GIMP_DEVEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gimp-devel+=	gimp-devel>=2.99.10
BUILDLINK_ABI_DEPENDS.gimp-devel?=	gimp-devel>=2.99.18nb10
BUILDLINK_PKGSRCDIR.gimp-devel?=	../../graphics/gimp-devel

.include "../../graphics/gegl/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# GIMP_DEVEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gimp-devel
