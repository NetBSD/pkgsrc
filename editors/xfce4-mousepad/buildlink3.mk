# $NetBSD: buildlink3.mk,v 1.2 2007/12/07 19:43:20 martti Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_MOUSEPAD_BUILDLINK3_MK:=	${XFCE4_MOUSEPAD_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	xfce4-mousepad
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-mousepad}
BUILDLINK_PACKAGES+=	xfce4-mousepad
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}xfce4-mousepad

.if ${XFCE4_MOUSEPAD_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.xfce4-mousepad+=	xfce4-mousepad>=0.2.13
BUILDLINK_PKGSRCDIR.xfce4-mousepad?=	../../editors/xfce4-mousepad
.endif	# XFCE4_MOUSEPAD_BUILDLINK3_MK

.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../devel/xfce4-dev-tools/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
