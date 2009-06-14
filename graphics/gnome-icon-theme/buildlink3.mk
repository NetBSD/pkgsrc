# $NetBSD: buildlink3.mk,v 1.15 2009/06/14 22:58:01 joerg Exp $

BUILDLINK_TREE+=	gnome-icon-theme

.if !defined(GNOME_ICON_THEME_BUILDLINK3_MK)
GNOME_ICON_THEME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-icon-theme+=	gnome-icon-theme>=2.8.0
BUILDLINK_ABI_DEPENDS.gnome-icon-theme?=	gnome-icon-theme>=2.12.1nb2
BUILDLINK_PKGSRCDIR.gnome-icon-theme?=	../../graphics/gnome-icon-theme

# intltool-{extract,merge,update} are Perl scripts included in the sources
# of packages that use gnome-icon-theme and are executed during build.
#
USE_TOOLS+=	perl
.endif # GNOME_ICON_THEME_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-icon-theme
