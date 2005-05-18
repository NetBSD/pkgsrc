# $NetBSD: buildlink3.mk,v 1.3 2005/05/18 06:10:30 martti Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
XFCE4_ICON_THEME_BUILDLINK3_MK:=	${XFCE4_ICON_THEME_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-icon-theme
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-icon-theme}
BUILDLINK_PACKAGES+=	xfce4-icon-theme

.if !empty(XFCE4_ICON_THEME_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xfce4-icon-theme+=	xfce4-icon-theme>=4.2.2
BUILDLINK_PKGSRCDIR.xfce4-icon-theme?=	../../graphics/xfce4-icon-theme
.endif	# XFCE4_ICON_THEME_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
