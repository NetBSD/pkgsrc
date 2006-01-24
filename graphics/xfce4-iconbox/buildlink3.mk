# $NetBSD: buildlink3.mk,v 1.9 2006/01/24 07:32:17 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_ICONBOX_BUILDLINK3_MK:=	${XFCE4_ICONBOX_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-iconbox
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-iconbox}
BUILDLINK_PACKAGES+=	xfce4-iconbox

.if !empty(XFCE4_ICONBOX_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xfce4-iconbox+=	xfce4-iconbox>=4.2.3
BUILDLINK_RECOMMENDED.xfce4-iconbox?=	xfce4-iconbox>=4.2.3nb1
BUILDLINK_PKGSRCDIR.xfce4-iconbox?=	../../graphics/xfce4-iconbox
.endif	# XFCE4_ICONBOX_BUILDLINK3_MK

.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
