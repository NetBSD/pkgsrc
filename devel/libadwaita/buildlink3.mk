# $NetBSD: buildlink3.mk,v 1.2 2023/01/03 17:36:18 wiz Exp $

BUILDLINK_TREE+=	libadwaita

.if !defined(LIBADWAITA_BUILDLINK3_MK)
LIBADWAITA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libadwaita+=	libadwaita>=1.0.5
BUILDLINK_ABI_DEPENDS.libadwaita?=	libadwaita>=1.1.3nb1
BUILDLINK_PKGSRCDIR.libadwaita?=	../../devel/libadwaita

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.endif	# LIBADWAITA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libadwaita
