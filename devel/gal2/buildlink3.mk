# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 03:04:28 xtraeme Exp $
#
# This Makefile fragment is included by packages that use gal2.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GAL2_BUILDLINK3_MK:=	${GAL2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gal2
.endif

.if !empty(GAL2_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			gal2
BUILDLINK_DEPENDS.gal2+=		gal2>=1.99.10nb3
BUILDLINK_PKGSRCDIR.gal2?=		../../devel/gal2

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"

.endif # GAL2_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
