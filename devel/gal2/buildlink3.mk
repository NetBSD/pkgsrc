# $NetBSD: buildlink3.mk,v 1.2 2004/03/05 19:25:10 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GAL2_BUILDLINK3_MK:=	${GAL2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gal2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngal2}
BUILDLINK_PACKAGES+=	gal2

.if !empty(GAL2_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gal2+=	gal2>=1.99.10nb3
BUILDLINK_PKGSRCDIR.gal2?=	../../devel/gal2

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"

.endif	# GAL2_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
