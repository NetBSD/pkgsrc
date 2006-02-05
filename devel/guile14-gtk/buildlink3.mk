# $NetBSD: buildlink3.mk,v 1.2 2006/02/05 23:08:43 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
GUILE_GTK_BUILDLINK3_MK:=	${GUILE_GTK_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	guile-gtk
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nguile-gtk}
BUILDLINK_PACKAGES+=	guile-gtk

.if !empty(GUILE_GTK_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.guile-gtk+=	guile-gtk>=0.19nb4
BUILDLINK_RECOMMENDED.guile-gtk+=	guile-gtk>=0.19nb7
BUILDLINK_PKGSRCDIR.guile-gtk?=	../../devel/guile14-gtk
.endif	# GUILE_GTK_BUILDLINK3_MK

.include "../../lang/guile14/buildlink3.mk"
.include "../../x11/gtk/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
