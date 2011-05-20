# $NetBSD: buildlink3.mk,v 1.1 2011/05/20 09:59:45 dmcmahill Exp $

BUILDLINK_TREE+=        guile-gnome-platform

.if !defined(GUILE_GNOME_PLATFORM_BUILDLINK3_MK)
GUILE_GNOME_PLATFORM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.guile-gnome-platform+=    guile-gnome-platform>=2.16.1nb10
BUILDLINK_PKGSRCDIR.guile-gnome-platform?=      ../../devel/guile-gnome

.include "../../devel/g-wrap/buildlink3.mk"
.include "../../graphics/guile-cairo/buildlink3.mk"
.endif  # GUILE_GNOME_PLATFORM_BUILDLINK3_MK

BUILDLINK_TREE+=        -guile-gnome-platform
