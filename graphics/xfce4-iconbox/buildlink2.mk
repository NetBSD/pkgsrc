# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/09/26 10:28:20 martti Exp $
#
# This Makefile fragment is included by packages that use xfce4-iconbox.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(XFCE4_ICONBOX_BUILDLINK2_MK)
XFCE4_ICONBOX_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			xfce4-iconbox
BUILDLINK_DEPENDS.xfce4-iconbox?=		xfce4-iconbox>=3.99.4
BUILDLINK_PKGSRCDIR.xfce4-iconbox?=		../../graphics/xfce4-iconbox

EVAL_PREFIX+=	BUILDLINK_PREFIX.xfce4-iconbox=xfce4-iconbox
BUILDLINK_PREFIX.xfce4-iconbox_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.xfce4-iconbox+=	lib/xfce4/mcs-plugins/xfce4-iconbox_settings.*

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"

BUILDLINK_TARGETS+=	xfce4-iconbox-buildlink

xfce4-iconbox-buildlink: _BUILDLINK_USE

.endif	# XFCE4_ICONBOX_BUILDLINK2_MK
