# $NetBSD: buildlink3.mk,v 1.2 2004/03/05 19:25:08 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBSHOUT_BUILDLINK3_MK:=	${LIBSHOUT_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libshout
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibshout}
BUILDLINK_PACKAGES+=	libshout

.if !empty(LIBSHOUT_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libshout+=	libshout>=2.0
BUILDLINK_PKGSRCDIR.libshout?=	../../audio/libshout

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.endif	# LIBSHOUT_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
