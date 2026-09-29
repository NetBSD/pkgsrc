# $NetBSD: buildlink3.mk,v 1.109 2026/09/29 06:05:39 wiz Exp $

BUILDLINK_TREE+=	gimp

.if !defined(GIMP_BUILDLINK3_MK)
GIMP_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gimp+=	gimp>=2.99.10
BUILDLINK_ABI_DEPENDS.gimp+=	gimp>=3.2.6nb3
BUILDLINK_PKGSRCDIR.gimp?=	../../graphics/gimp

.include "../../graphics/gegl/buildlink3.mk"
.include "../../graphics/gexiv2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.endif	# GIMP_BUILDLINK3_MK

BUILDLINK_TREE+=	-gimp
