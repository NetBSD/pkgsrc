# $NetBSD: buildlink3.mk,v 1.1 2004/02/14 18:22:56 minskim Exp $
#
# This Makefile fragment is included by packages that use faces.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
FACES_BUILDLINK3_MK:=	${FACES_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	faces
.endif

.if !empty(FACES_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			faces
BUILDLINK_DEPENDS.faces+=		faces>=1.6.1nb1
BUILDLINK_PKGSRCDIR.faces?=		../../mail/faces

.endif # FACES_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
