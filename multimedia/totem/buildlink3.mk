# $NetBSD: buildlink3.mk,v 1.1 2006/03/30 21:36:13 jmmv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
TOTEM_BUILDLINK3_MK:=	${TOTEM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	totem
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntotem}
BUILDLINK_PACKAGES+=	totem

.if !empty(TOTEM_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.totem+=	{totem,totem-xine}>=1.4.0
BUILDLINK_PKGSRCDIR.totem?=	../../multimedia/totem
.endif	# TOTEM_BUILDLINK3_MK

.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
