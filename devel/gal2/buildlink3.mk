# $NetBSD: buildlink3.mk,v 1.10 2006/01/24 07:32:02 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GAL2_BUILDLINK3_MK:=	${GAL2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gal2
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngal2}
BUILDLINK_PACKAGES+=	gal2

.if !empty(GAL2_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gal2+=	gal2>=2.4.0
BUILDLINK_DEPENDS.gal2+=	gal2<2.5.0
BUILDLINK_RECOMMENDED.gal2?=	gal2>=2.4.3nb2
BUILDLINK_PKGSRCDIR.gal2?=	../../devel/gal2
.endif	# GAL2_BUILDLINK3_MK

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
