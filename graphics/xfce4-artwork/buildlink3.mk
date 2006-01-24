# $NetBSD: buildlink3.mk,v 1.4 2006/01/24 07:32:17 wiz Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_ARTWORK_BUILDLINK3_MK:=	${XFCE4_ARTWORK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-artwork
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-artwork}
BUILDLINK_PACKAGES+=	xfce4-artwork

.if !empty(XFCE4_ARTWORK_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xfce4-artwork+=	xfce4-artwork>=0.0.4nb5
BUILDLINK_RECOMMENDED.xfce4-artwork?=	xfce4-artwork>=0.0.4nb6
BUILDLINK_PKGSRCDIR.xfce4-artwork?=	../../graphics/xfce4-artwork
.endif	# XFCE4_ARTWORK_BUILDLINK3_MK

.include "../../x11/xfce4-desktop/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
