# $NetBSD: buildlink3.mk,v 1.2 2008/11/01 17:54:00 wiz Exp $

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

.include "../../inputmethod/tomoe/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
