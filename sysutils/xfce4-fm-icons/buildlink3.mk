# $NetBSD: buildlink3.mk,v 1.3.2.1 2004/07/14 11:17:19 agc Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_FM_ICONS_BUILDLINK3_MK:=	${XFCE4_FM_ICONS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-fm-icons
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-fm-icons}
BUILDLINK_PACKAGES+=	xfce4-fm-icons

.if !empty(XFCE4_FM_ICONS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xfce4-fm-icons+=	xfce4-fm-icons>=4.0.6
BUILDLINK_PKGSRCDIR.xfce4-fm-icons?=	../../sysutils/xfce4-fm-icons
.endif	# XFCE4_FM_ICONS_BUILDLINK3_MK

.include "../../sysutils/xfce4-fm/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
