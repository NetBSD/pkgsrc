# $NetBSD: buildlink3.mk,v 1.5 2006/07/08 23:11:02 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
TOTEM_BUILDLINK3_MK:=	${TOTEM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	totem
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntotem}
BUILDLINK_PACKAGES+=	totem
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}totem

.if !empty(TOTEM_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.totem+=	{totem,totem-xine}>=1.4.0
BUILDLINK_ABI_DEPENDS.totem?=	totem>=1.4.0nb2
BUILDLINK_PKGSRCDIR.totem?=	../../multimedia/totem
.endif	# TOTEM_BUILDLINK3_MK

.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
