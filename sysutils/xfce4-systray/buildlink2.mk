# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/09/26 10:36:06 martti Exp $
#
# This Makefile fragment is included by packages that use xfce4-systray.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(XFCE4_SYSTRAY_BUILDLINK2_MK)
XFCE4_SYSTRAY_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			xfce4-systray
BUILDLINK_DEPENDS.xfce4-systray?=		xfce4-systray>=4.0.0
BUILDLINK_PKGSRCDIR.xfce4-systray?=		../../sysutils/xfce4-systray

EVAL_PREFIX+=	BUILDLINK_PREFIX.xfce4-systray=xfce4-systray
BUILDLINK_PREFIX.xfce4-systray_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.xfce4-systray+=	lib/xfce4/panel-plugins/libsystray.*

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/xfce4-panel/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"

BUILDLINK_TARGETS+=	xfce4-systray-buildlink

xfce4-systray-buildlink: _BUILDLINK_USE

.endif	# XFCE4_SYSTRAY_BUILDLINK2_MK
