# $NetBSD: buildlink2.mk,v 1.1.1.1 2003/09/26 10:31:32 martti Exp $
#
# This Makefile fragment is included by packages that use xfce4-print.
#
# This file was created automatically using createbuildlink 2.6.
#

.if !defined(XFCE4_PRINT_BUILDLINK2_MK)
XFCE4_PRINT_BUILDLINK2_MK=	# defined

BUILDLINK_PACKAGES+=			xfce4-print
BUILDLINK_DEPENDS.xfce4-print?=		xfce4-print>=4.0.0
BUILDLINK_PKGSRCDIR.xfce4-print?=		../../print/xfce4-print

EVAL_PREFIX+=	BUILDLINK_PREFIX.xfce4-print=xfce4-print
BUILDLINK_PREFIX.xfce4-print_DEFAULT=	${X11PREFIX}
BUILDLINK_FILES.xfce4-print+=	lib/libxfprint.*

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink2.mk"
.include "../../devel/glib2/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"

BUILDLINK_TARGETS+=	xfce4-print-buildlink

xfce4-print-buildlink: _BUILDLINK_USE

.endif	# XFCE4_PRINT_BUILDLINK2_MK
