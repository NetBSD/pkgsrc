# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/09/26 10:32:34 martti Exp $
#
# This Makefile fragment is included by packages that use xfce4-fm.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(XFCE4_FM_BUILDLINK2_MK)
XFCE4_FM_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			xfce4-fm
BUILDLINK_DEPENDS.xfce4-fm?=		xfce4-fm>=4.0.0
BUILDLINK_PKGSRCDIR.xfce4-fm?=		../../sysutils/xfce4-fm

EVAL_PREFIX+=	BUILDLINK_PREFIX.xfce4-fm=xfce4-fm
BUILDLINK_PREFIX.xfce4-fm_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.xfce4-fm+=	lib/libxffm.*
BUILDLINK_FILES.xfce4-fm+=	lib/libxffm_actions.*
BUILDLINK_FILES.xfce4-fm+=	lib/libxffm_apps.*
BUILDLINK_FILES.xfce4-fm+=	lib/libxffm_book.*
BUILDLINK_FILES.xfce4-fm+=	lib/libxffm_calls.*
BUILDLINK_FILES.xfce4-fm+=	lib/libxffm_fgr.*
BUILDLINK_FILES.xfce4-fm+=	lib/libxffm_fstab.*
BUILDLINK_FILES.xfce4-fm+=	lib/libxffm_tubo.*
BUILDLINK_FILES.xfce4-fm+=	lib/libxffmsmb.*
BUILDLINK_FILES.xfce4-fm+=	lib/pkgconfig/xffm-1.0.pc
BUILDLINK_FILES.xfce4-fm+=	lib/xfce4/mcs-plugins/libxffmsettings.*

.include "../../databases/dbh/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"

BUILDLINK_TARGETS+=	xfce4-fm-buildlink

xfce4-fm-buildlink: _BUILDLINK_USE

.endif	# XFCE4_FM_BUILDLINK2_MK
