# $NetBSD: buildlink3.mk,v 1.40 2012/10/02 17:11:53 tron Exp $

BUILDLINK_TREE+=	xfce4-print

.if !defined(XFCE4_PRINT_BUILDLINK3_MK)
XFCE4_PRINT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.xfce4-print+=	xfce4-print>=4.6.0
BUILDLINK_ABI_DEPENDS.xfce4-print+=	xfce4-print>=4.6.1nb13
BUILDLINK_PKGSRCDIR.xfce4-print?=	../../print/xfce4-print

.include "../../devel/glib2/buildlink3.mk"
.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"

pkgbase := xfce4-print
.include "../../mk/pkg-build-options.mk"

.if !empty(PKG_BUILD_OPTIONS.xfce4-print:Mcups)
.  include "../../print/cups/buildlink3.mk"
.endif
.endif # XFCE4_PRINT_BUILDLINK3_MK

BUILDLINK_TREE+=	-xfce4-print
