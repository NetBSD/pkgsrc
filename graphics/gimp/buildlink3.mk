# $NetBSD: buildlink3.mk,v 1.103 2025/10/23 20:37:29 wiz Exp $

BUILDLINK_TREE+=	gimp

.if !defined(GIMP_BUILDLINK3_MK)
GIMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gimp+=	gimp>=2.99.10
BUILDLINK_ABI_DEPENDS.gimp+=	gimp>=3.0.4nb9
BUILDLINK_PKGSRCDIR.gimp?=	../../graphics/gimp

.include "../../graphics/gegl/buildlink3.mk"
.include "../../graphics/gexiv2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# GIMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-gimp
