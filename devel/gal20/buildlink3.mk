# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/10/01 12:42:50 rh Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GAL20_BUILDLINK3_MK:=	${GAL20_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gal20
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngal20}
BUILDLINK_PACKAGES+=	gal20

.if !empty(GAL20_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gal20+=	gal20>=1.99.11
BUILDLINK_PKGSRCDIR.gal20?=	../../devel/gal20
.endif	# GAL20_BUILDLINK3_MK

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
