# $NetBSD: buildlink3.mk,v 1.19 2012/05/07 01:53:34 dholland Exp $

BUILDLINK_TREE+=	gnome-icon-theme

.if !defined(GNOME_ICON_THEME_BUILDLINK3_MK)
GNOME_ICON_THEME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gnome-icon-theme+=	gnome-icon-theme>=2.8.0
BUILDLINK_ABI_DEPENDS.gnome-icon-theme+=	gnome-icon-theme>=2.12.1nb2
BUILDLINK_PKGSRCDIR.gnome-icon-theme?=	../../graphics/gnome-icon-theme

# intltool-{extract,merge,update} are Perl scripts included in the sources
# of packages that use gnome-icon-theme and are executed during build.
#
USE_TOOLS+=	perl

.include "../../mk/bsd.fast.prefs.mk"

.if !defined(GNOME_ICON_THEME_DEPEND_ONLY)
EVAL_PREFIX+=		PREFIX.gtk2=gtk2+
FILES_SUBST+=		GTK_UPDATE_ICON_CACHE="${PREFIX.gtk2}/bin/gtk-update-icon-cache"
FILES_SUBST+=		ICON_THEME_DIR="${BUILDLINK_PREFIX.gnome-icon-theme}/share/icons/gnome"
INSTALL_TEMPLATES+=	../../graphics/gnome-icon-theme/files/icon-cache.tmpl
DEINSTALL_TEMPLATES+=	../../graphics/gnome-icon-theme/files/icon-cache.tmpl

PRINT_PLIST_AWK+=	/^share\/icons\/gnome\/icon-theme.cache$$/ { next; }
CHECK_FILES_SKIP+=	${PREFIX}/share/icons/gnome/icon-theme.cache

.if !defined(NOOP_GTK_UPDATE_ICON_CACHE)
NOOP_GTK_UPDATE_ICON_CACHE=
TOOLS_NOOP+=		gtk-update-icon-cache
.endif

.endif  # GNOME_ICON_THEME_DEPEND_ONLY
.endif # GNOME_ICON_THEME_BUILDLINK3_MK

BUILDLINK_TREE+=	-gnome-icon-theme
