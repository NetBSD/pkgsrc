# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/08/30 20:53:20 adrianp Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBMILTER_BUILDLINK3_MK:=	${LIBMILTER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libmilter
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibmilter}
BUILDLINK_PACKAGES+=	libmilter

.if !empty(LIBMILTER_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libmilter+=	libmilter>=8.12.9nb1
BUILDLINK_PKGSRCDIR.libmilter?=	../../mail/libmilter812
BUILDLINK_DEPMETHOD.libmilter?=	build

PTHREAD_OPTS+=		require
.endif	# LIBMILTER_BUILDLINK3_MK

.include "../../mk/pthread.buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
