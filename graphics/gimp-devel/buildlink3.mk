# $NetBSD: buildlink3.mk,v 1.15 2025/04/08 12:22:11 adam Exp $

BUILDLINK_TREE+=	gimp-devel

.if !defined(GIMP_DEVEL_BUILDLINK3_MK)
GIMP_DEVEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gimp-devel+=	gimp-devel>=2.99.10
BUILDLINK_ABI_DEPENDS.gimp-devel+=	gimp-devel>=3.0.0rc1nb4
BUILDLINK_PKGSRCDIR.gimp-devel?=	../../graphics/gimp-devel

.include "../../graphics/gegl/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# GIMP_DEVEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gimp-devel
