# $NetBSD: buildlink3.mk,v 1.1 2004/03/05 19:09:22 minskim Exp $
#
# This Makefile fragment is included by packages that use Canna-lib.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
CANNA_LIB_BUILDLINK3_MK:=	${CANNA_LIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	Canna-lib
.endif

.if !empty(CANNA_LIB_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			Canna-lib
BUILDLINK_DEPENDS.Canna-lib+=		Canna-lib>=3.6pl3
BUILDLINK_PKGSRCDIR.Canna-lib?=		../../inputmethod/canna-lib

.endif # CANNA_LIB_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
