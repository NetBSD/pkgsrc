# $NetBSD: buildlink3.mk,v 1.2 2004/03/05 19:25:10 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GIBLIB_BUILDLINK3_MK:=	${GIBLIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	giblib
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngiblib}
BUILDLINK_PACKAGES+=	giblib

.if !empty(GIBLIB_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.giblib+=	giblib>=1.2.3nb3
BUILDLINK_PKGSRCDIR.giblib?=	../../devel/giblib

.include "../../graphics/imlib2/buildlink3.mk"

.endif	# GIBLIB_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
