# $NetBSD: buildlink3.mk,v 1.2 2004/10/03 00:13:07 tv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBHYDROGEN_BUILDLINK3_MK:=	${LIBHYDROGEN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libhydrogen
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibhydrogen}
BUILDLINK_PACKAGES+=	libhydrogen

.if !empty(LIBHYDROGEN_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libhydrogen+=		libhydrogen>=0.8.0
BUILDLINK_RECOMMENDED.libhydrogen+=	libhydrogen>=0.8.0nb1
BUILDLINK_PKGSRCDIR.libhydrogen?=	../../audio/libhydrogen
.endif	# LIBHYDROGEN_BUILDLINK3_MK

.include "../../audio/libaudiofile/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
