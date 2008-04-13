# $NetBSD: buildlink3.mk,v 1.1.1.1 2008/04/13 06:06:40 obache Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
TOMOE_GTK_BUILDLINK3_MK:=	${TOMOE_GTK_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	tomoe-gtk
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ntomoe-gtk}
BUILDLINK_PACKAGES+=	tomoe-gtk
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}tomoe-gtk

.if ${TOMOE_GTK_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.tomoe-gtk+=	tomoe-gtk>=0.6.0
BUILDLINK_PKGSRCDIR.tomoe-gtk?=	../../inputmethod/tomoe-gtk
.endif	# TOMOE_GTK_BUILDLINK3_MK

.include "../../fonts/gucharmap/buildlink3.mk"
.include "../../inputmethod/tomoe/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
