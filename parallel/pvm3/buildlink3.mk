# $NetBSD: buildlink3.mk,v 1.1 2004/02/25 03:47:50 dmcmahill Exp $
#
# This Makefile fragment is included by packages that use pvm.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PVM_BUILDLINK3_MK:=	${PVM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pvm
.endif

.if !empty(PVM_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			pvm
BUILDLINK_DEPENDS.pvm+=		pvm>=3.4.3
BUILDLINK_PKGSRCDIR.pvm?=		../../parallel/pvm3

.endif # PVM_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
