# $NetBSD: buildlink3.mk,v 1.1 2004/02/27 23:37:26 grant Exp $
#
# This Makefile fragment is included by packages that use unproven-pthreads.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
UNPROVEN_PTHREADS_BUILDLINK3_MK:=	${UNPROVEN_PTHREADS_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	unproven-pthreads
.endif

.if !empty(UNPROVEN_PTHREADS_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			unproven-pthreads
BUILDLINK_DEPENDS.unproven-pthreads+=		unproven-pthreads>=0.17
BUILDLINK_PKGSRCDIR.unproven-pthreads?=		../../devel/unproven-pthreads

.endif # UNPROVEN_PTHREADS_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
