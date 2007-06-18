# $NetBSD: buildlink3.mk,v 1.1.1.1 2007/06/18 00:38:58 dmcmahill Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GUILE16_GTK_BUILDLINK3_MK:=	${GUILE16_GTK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	guile16-gtk
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nguile16-gtk}
BUILDLINK_PACKAGES+=	guile16-gtk
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}guile16-gtk

.if !empty(GUILE16_GTK_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.guile16-gtk+=	guile16-gtk>=0.5
BUILDLINK_ABI_DEPENDS.guile16-gtk?=	guile16-gtk>=0.5
BUILDLINK_PKGSRCDIR.guile16-gtk?=	../../devel/guile16-gtk
.endif	# GUILE16_GTK_BUILDLINK3_MK

.include "../../lang/guile16/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
