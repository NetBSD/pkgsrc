# $NetBSD: buildlink3.mk,v 1.1 2004/05/03 15:58:55 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
G_WRAP_BUILDLINK3_MK:=	${G_WRAP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	g-wrap
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ng-wrap}
BUILDLINK_PACKAGES+=	g-wrap

.if !empty(G_WRAP_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.g-wrap+=	g-wrap>=1.3.4nb3
BUILDLINK_PKGSRCDIR.g-wrap?=	../../devel/g-wrap
.endif	# G_WRAP_BUILDLINK3_MK

.include "../../devel/glib/buildlink3.mk"
.include "../../lang/guile14/buildlink3.mk"
.include "../../devel/guile-gtk/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
