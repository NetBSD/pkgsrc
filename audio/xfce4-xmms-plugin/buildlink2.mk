# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/12/03 06:38:40 martti Exp $
#
# This Makefile fragment is included by packages that use xfce4-xmms-plugin.
#
# This file was created automatically using createbuildlink 2.8.
#

.if !defined(XFCE4_XMMS_PLUGIN_BUILDLINK2_MK)
XFCE4_XMMS_PLUGIN_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			xfce4-xmms-plugin
BUILDLINK_DEPENDS.xfce4-xmms-plugin?=		xfce4-xmms-plugin>=0.1.1
BUILDLINK_PKGSRCDIR.xfce4-xmms-plugin?=		../../audio/xfce4-xmms-plugin

EVAL_PREFIX+=	BUILDLINK_PREFIX.xfce4-xmms-plugin=xfce4-xmms-plugin
BUILDLINK_PREFIX.xfce4-xmms-plugin_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.xfce4-xmms-plugin+=	lib/xfce4/panel-plugins/libxmms.*

.include "../../audio/xmms/buildlink2.mk"
.include "../../x11/xfce4-panel/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"

BUILDLINK_TARGETS+=	xfce4-xmms-plugin-buildlink

xfce4-xmms-plugin-buildlink: _BUILDLINK_USE

.endif	# XFCE4_XMMS_PLUGIN_BUILDLINK2_MK
