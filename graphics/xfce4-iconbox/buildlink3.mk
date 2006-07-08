# $NetBSD: buildlink3.mk,v 1.16 2006/07/08 23:10:53 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_ICONBOX_BUILDLINK3_MK:=	${XFCE4_ICONBOX_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-iconbox
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-iconbox}
BUILDLINK_PACKAGES+=	xfce4-iconbox
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-iconbox

.if !empty(XFCE4_ICONBOX_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.xfce4-iconbox+=	xfce4-iconbox>=4.2.3
BUILDLINK_ABI_DEPENDS.xfce4-iconbox?=	xfce4-iconbox>=4.2.3nb4
BUILDLINK_PKGSRCDIR.xfce4-iconbox?=	../../graphics/xfce4-iconbox
.endif	# XFCE4_ICONBOX_BUILDLINK3_MK

.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
