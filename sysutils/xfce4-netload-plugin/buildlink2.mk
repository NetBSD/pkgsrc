# $NetBSD: buildlink2.mk,v 1.2 2003/09/27 06:57:16 martti Exp $
#
# This Makefile fragment is included by packages that use xfce4-netload-plugin.
#
# This file was created automatically using createbuildlink 2.7.
#

.if !defined(XFCE4_NETLOAD_PLUGIN_BUILDLINK2_MK)
XFCE4_NETLOAD_PLUGIN_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			xfce4-netload-plugin
BUILDLINK_DEPENDS.xfce4-netload-plugin?=		xfce4-netload-plugin>=0.2.0pre6
BUILDLINK_PKGSRCDIR.xfce4-netload-plugin?=		../../sysutils/xfce4-netload-plugin

EVAL_PREFIX+=	BUILDLINK_PREFIX.xfce4-netload-plugin=xfce4-netload-plugin
BUILDLINK_PREFIX.xfce4-netload-plugin_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.xfce4-netload-plugin+=	lib/xfce4/panel-plugins/libnetload.*

.include "../../x11/xfce4-panel/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"

BUILDLINK_TARGETS+=	xfce4-netload-plugin-buildlink

xfce4-netload-plugin-buildlink: _BUILDLINK_USE

.endif	# XFCE4_NETLOAD_PLUGIN_BUILDLINK2_MK
