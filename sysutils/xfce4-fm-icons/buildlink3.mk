# $NetBSD: buildlink3.mk,v 1.1 2004/03/10 11:53:37 xtraeme Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_FM_ICONS_BUILDLINK3_MK:=	${XFCE4_FM_ICONS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-fm-icons
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-fm-icons}
BUILDLINK_PACKAGES+=	xfce4-fm-icons

.if !empty(XFCE4_FM_ICONS_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xfce4-fm-icons+=	xfce4-fm-icons>=4.0.4nb1
BUILDLINK_PKGSRCDIR.xfce4-fm-icons?=	../../sysutils/xfce4-fm-icons

.include "../../sysutils/xfce4-fm/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

.endif	# XFCE4_FM_ICONS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
