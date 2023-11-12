# $NetBSD: buildlink3.mk,v 1.9 2023/11/12 13:21:04 wiz Exp $

BUILDLINK_TREE+=	libadwaita

.if !defined(LIBADWAITA_BUILDLINK3_MK)
LIBADWAITA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libadwaita+=	libadwaita>=1.0.5
BUILDLINK_ABI_DEPENDS.libadwaita+=	libadwaita>=1.4.0nb3
BUILDLINK_PKGSRCDIR.libadwaita?=	../../devel/libadwaita

.include "../../devel/appstream/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.endif	# LIBADWAITA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libadwaita
