# $NetBSD: buildlink3.mk,v 1.14 2009/03/20 19:24:39 joerg Exp $

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

.  include "../../mk/bsd.fast.prefs.mk"

dirs!=	${GREP} "^@dirrm" ${.CURDIR}/../../graphics/gnome-icon-theme/PLIST | \
	${CUT} -d ' ' -f 2
.  for d in ${dirs}
PRINT_PLIST_AWK+=	/^@dirrm ${d:S/\//\\\//g}$$/ \
			{ print "@comment in gnome-icon-theme: " $$0; next; }
.  endfor
.  undef dirs
.endif # GNOME_ICON_THEME_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-icon-theme
