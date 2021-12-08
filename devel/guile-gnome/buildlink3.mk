# $NetBSD: buildlink3.mk,v 1.7 2021/12/08 16:01:53 adam Exp $

BUILDLINK_TREE+=	guile-gnome-platform

.if !defined(GUILE_GNOME_PLATFORM_BUILDLINK3_MK)
GUILE_GNOME_PLATFORM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.guile-gnome-platform+=	guile-gnome-platform>=2.16.1nb10
BUILDLINK_ABI_DEPENDS.guile-gnome-platform?=	guile-gnome-platform>=2.16.5nb11
BUILDLINK_PKGSRCDIR.guile-gnome-platform?=	../../devel/guile-gnome

.include "../../devel/g-wrap/buildlink3.mk"
.include "../../graphics/guile-cairo/buildlink3.mk"
.endif  # GUILE_GNOME_PLATFORM_BUILDLINK3_MK

BUILDLINK_TREE+=	-guile-gnome-platform
