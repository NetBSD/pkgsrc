# $NetBSD: buildlink3.mk,v 1.4 2004/10/03 00:13:07 tv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBSHOUT_BUILDLINK3_MK:=	${LIBSHOUT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libshout
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibshout}
BUILDLINK_PACKAGES+=	libshout

.if !empty(LIBSHOUT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libshout+=	libshout>=2.0
BUILDLINK_RECOMMENDED.libshout+=	libshout>=2.0nb1
BUILDLINK_PKGSRCDIR.libshout?=	../../audio/libshout
.endif	# LIBSHOUT_BUILDLINK3_MK

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
