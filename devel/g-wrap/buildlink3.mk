# $NetBSD: buildlink3.mk,v 1.6 2006/02/05 23:08:42 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
G_WRAP_BUILDLINK3_MK:=	${G_WRAP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	g-wrap
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ng-wrap}
BUILDLINK_PACKAGES+=	g-wrap

.if !empty(G_WRAP_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.g-wrap+=	g-wrap>=1.9.5
BUILDLINK_RECOMMENDED.g-wrap?=	g-wrap>=1.9.6nb1
BUILDLINK_PKGSRCDIR.g-wrap?=	../../devel/g-wrap
.endif	# G_WRAP_BUILDLINK3_MK

.include "../../lang/guile/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
