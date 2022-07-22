# $NetBSD: buildlink3.mk,v 1.1 2022/07/22 20:18:54 wiz Exp $

BUILDLINK_TREE+=	gimp

.if !defined(GIMP_BUILDLINK3_MK)
GIMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gimp+=	gimp>=2.99
BUILDLINK_PKGSRCDIR.gimp?=	../../graphics/gimp-devel

.include "../../graphics/gegl/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif # GIMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-gimp
