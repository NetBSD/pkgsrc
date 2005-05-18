# $NetBSD: buildlink3.mk,v 1.8 2005/05/18 06:10:30 martti Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_MIXER_BUILDLINK3_MK:=	${XFCE4_MIXER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-mixer
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-mixer}
BUILDLINK_PACKAGES+=	xfce4-mixer

.if !empty(XFCE4_MIXER_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xfce4-mixer+=	xfce4-mixer>=4.2.2
BUILDLINK_PKGSRCDIR.xfce4-mixer?=	../../audio/xfce4-mixer
.endif	# XFCE4_MIXER_BUILDLINK3_MK

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
