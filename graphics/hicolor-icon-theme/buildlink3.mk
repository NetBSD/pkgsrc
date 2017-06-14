# $NetBSD: buildlink3.mk,v 1.20 2017/06/14 16:23:09 prlw1 Exp $

BUILDLINK_TREE+=	hicolor-icon-theme

.if !defined(HICOLOR_ICON_THEME_BUILDLINK3_MK)
HICOLOR_ICON_THEME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.hicolor-icon-theme+=	hicolor-icon-theme>=0.4
BUILDLINK_ABI_DEPENDS.hicolor-icon-theme+=	hicolor-icon-theme>=0.9nb1
BUILDLINK_PKGSRCDIR.hicolor-icon-theme?=../../graphics/hicolor-icon-theme

.include "../../mk/bsd.fast.prefs.mk"

.if !defined(HICOLOR_ICON_THEME_DEPEND_ONLY)

ICON_THEMES=	yes

.if !defined(NOOP_GTK_UPDATE_ICON_CACHE)
NOOP_GTK_UPDATE_ICON_CACHE=
TOOLS_NOOP+=		gtk-update-icon-cache
.endif

.endif	# HICOLOR_ICON_THEME_DEPEND_ONLY
.endif # HICOLOR_ICON_THEME_BUILDLINK3_MK

BUILDLINK_TREE+=	-hicolor-icon-theme
