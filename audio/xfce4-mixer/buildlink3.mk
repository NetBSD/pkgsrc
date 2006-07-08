# $NetBSD: buildlink3.mk,v 1.17 2006/07/08 23:10:38 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_MIXER_BUILDLINK3_MK:=	${XFCE4_MIXER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-mixer
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-mixer}
BUILDLINK_PACKAGES+=	xfce4-mixer
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-mixer

.if !empty(XFCE4_MIXER_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.xfce4-mixer+=	xfce4-mixer>=4.2.3
BUILDLINK_ABI_DEPENDS.xfce4-mixer?=	xfce4-mixer>=4.2.3nb4
BUILDLINK_PKGSRCDIR.xfce4-mixer?=	../../audio/xfce4-mixer
.endif	# XFCE4_MIXER_BUILDLINK3_MK

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
