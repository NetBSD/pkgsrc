# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/12/14 11:06:42 obache Exp $
#

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
CLUTTER_GTK_BUILDLINK3_MK:=	${CLUTTER_GTK_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	clutter-gtk
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nclutter-gtk}
BUILDLINK_PACKAGES+=	clutter-gtk
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}clutter-gtk

.if ${CLUTTER_GTK_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.clutter-gtk+=	clutter-gtk>=0.8.0
BUILDLINK_PKGSRCDIR.clutter-gtk?=	../../graphics/clutter-gtk
.endif	# CLUTTER_GTK_BUILDLINK3_MK

.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/clutter/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
