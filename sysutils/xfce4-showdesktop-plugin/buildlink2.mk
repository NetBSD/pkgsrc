# $NetBSD: buildlink2.mk,v 1.2 2003/09/27 06:57:16 martti Exp $
#
# This Makefile fragment is included by packages that use xfce4-showdesktop-plugin.
#
# This file was created automatically using createbuildlink 2.7.
#

.if !defined(XFCE4_SHOWDESKTOP_PLUGIN_BUILDLINK2_MK)
XFCE4_SHOWDESKTOP_PLUGIN_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			xfce4-showdesktop-plugin
BUILDLINK_DEPENDS.xfce4-showdesktop-plugin?=		xfce4-showdesktop-plugin>=0.1.1
BUILDLINK_PKGSRCDIR.xfce4-showdesktop-plugin?=		../../sysutils/xfce4-showdesktop-plugin

EVAL_PREFIX+=	BUILDLINK_PREFIX.xfce4-showdesktop-plugin=xfce4-showdesktop-plugin
BUILDLINK_PREFIX.xfce4-showdesktop-plugin_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.xfce4-showdesktop-plugin+=	lib/xfce4/panel-plugins/libshowdesktop.*

.include "../../x11/xfce4-panel/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"

BUILDLINK_TARGETS+=	xfce4-showdesktop-plugin-buildlink

xfce4-showdesktop-plugin-buildlink: _BUILDLINK_USE

.endif	# XFCE4_SHOWDESKTOP_PLUGIN_BUILDLINK2_MK
