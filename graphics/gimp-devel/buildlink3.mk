# $NetBSD: buildlink3.mk,v 1.9 2023/11/14 14:02:02 wiz Exp $

BUILDLINK_TREE+=	gimp-devel

.if !defined(GIMP_DEVEL_BUILDLINK3_MK)
GIMP_DEVEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gimp-devel+=	gimp-devel>=2.99.10
BUILDLINK_ABI_DEPENDS.gimp-devel?=	gimp-devel>=2.99.16nb6
BUILDLINK_PKGSRCDIR.gimp-devel?=	../../graphics/gimp-devel

.include "../../graphics/gegl/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# GIMP_DEVEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gimp-devel
