# $NetBSD: buildlink3.mk,v 1.3 2023/01/29 21:14:29 ryoon Exp $

BUILDLINK_TREE+=	libadwaita

.if !defined(LIBADWAITA_BUILDLINK3_MK)
LIBADWAITA_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libadwaita+=	libadwaita>=1.0.5
BUILDLINK_ABI_DEPENDS.libadwaita?=	libadwaita>=1.1.3nb2
BUILDLINK_PKGSRCDIR.libadwaita?=	../../devel/libadwaita

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.endif	# LIBADWAITA_BUILDLINK3_MK

BUILDLINK_TREE+=	-libadwaita
