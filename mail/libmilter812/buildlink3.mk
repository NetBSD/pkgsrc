# $NetBSD: buildlink3.mk,v 1.4 2006/07/08 22:39:25 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBMILTER_BUILDLINK3_MK:=	${LIBMILTER_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libmilter
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibmilter}
BUILDLINK_PACKAGES+=	libmilter
BUILDLINK_ORDER+=	libmilter

.if !empty(LIBMILTER_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libmilter+=	libmilter>=8.12.9nb1
BUILDLINK_PKGSRCDIR.libmilter?=	../../mail/libmilter812
BUILDLINK_DEPMETHOD.libmilter?=	build

PTHREAD_OPTS+=		require
.endif	# LIBMILTER_BUILDLINK3_MK

.include "../../mk/pthread.buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
