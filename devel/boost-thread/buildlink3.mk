# $NetBSD: buildlink3.mk,v 1.1 2004/06/06 23:51:37 tv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
BOOST_THREAD_BUILDLINK3_MK:=	${BOOST_THREAD_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	boost-thread
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nboost-thread}
BUILDLINK_PACKAGES+=	boost-thread

.if !empty(BOOST_THREAD_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.boost-thread+=	boost-thread>=1.31.0
BUILDLINK_PKGSRCDIR.boost-thread?=	../../devel/boost-thread
.endif	# BOOST_THREAD_BUILDLINK3_MK

.include "../../mk/pthread.buildlink3.mk"
.include "../../devel/boost/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
