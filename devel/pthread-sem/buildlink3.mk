# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/01/20 21:29:10 rh Exp $
#
# This Makefile fragment is included by packages that use pthread-sem.
#

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
PTHREAD_SEM_BUILDLINK3_MK:=	${PTHREAD_SEM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pthread-sem
.endif

.if !empty(PTHREAD_SEM_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			pthread-sem
BUILDLINK_DEPENDS.pthread-sem?=		pthread-sem>=1.0
BUILDLINK_PKGSRCDIR.pthread-sem?=	../../devel/pthread-sem

.endif # PTHREAD_SEM_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
