# $NetBSD: buildlink3.mk,v 1.1 2004/03/10 11:59:31 xtraeme Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
XFCE4_ARTWORK_BUILDLINK3_MK:=	${XFCE4_ARTWORK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xfce4-artwork
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nxfce4-artwork}
BUILDLINK_PACKAGES+=	xfce4-artwork

.if !empty(XFCE4_ARTWORK_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.xfce4-artwork+=	xfce4-artwork>=0.0.4nb4
BUILDLINK_PKGSRCDIR.xfce4-artwork?=	../../graphics/xfce4-artwork

.include "../../x11/xfce4-desktop/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"

.endif	# XFCE4_ARTWORK_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
