# $NetBSD: buildlink3.mk,v 1.12 2006/07/08 23:11:09 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_APPFINDER_BUILDLINK3_MK:=	${XFCE4_APPFINDER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-appfinder
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-appfinder}
BUILDLINK_PACKAGES+=	xfce4-appfinder
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-appfinder

.if !empty(XFCE4_APPFINDER_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.xfce4-appfinder+=	xfce4-appfinder>=4.2.3
BUILDLINK_ABI_DEPENDS.xfce4-appfinder?=	xfce4-appfinder>=4.2.3nb3
BUILDLINK_PKGSRCDIR.xfce4-appfinder?=	../../sysutils/xfce4-appfinder
.endif	# XFCE4_APPFINDER_BUILDLINK3_MK

.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
