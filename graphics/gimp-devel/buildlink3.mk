# $NetBSD: buildlink3.mk,v 1.5 2023/01/29 21:14:39 ryoon Exp $

BUILDLINK_TREE+=	gimp-devel

.if !defined(GIMP_DEVEL_BUILDLINK3_MK)
GIMP_DEVEL_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gimp-devel+=	gimp-devel>=2.99.10
BUILDLINK_ABI_DEPENDS.gimp-devel?=	gimp-devel>=2.99.14nb2
BUILDLINK_PKGSRCDIR.gimp-devel?=	../../graphics/gimp-devel

.include "../../graphics/gegl/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# GIMP_DEVEL_BUILDLINK3_MK

BUILDLINK_TREE+=	-gimp-devel
