# $NetBSD: buildlink3.mk,v 1.2 2004/10/03 00:13:02 tv Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBDVDPLAY_BUILDLINK3_MK:=	${LIBDVDPLAY_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libdvdplay
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibdvdplay}
BUILDLINK_PACKAGES+=	libdvdplay

.if !empty(LIBDVDPLAY_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libdvdplay+=		libdvdplay>=1.0.1
BUILDLINK_RECOMMENDED.libdvdplay+=	libdvdplay>=1.0.1nb2
BUILDLINK_PKGSRCDIR.libdvdplay?=	../../multimedia/libdvdplay
.endif	# LIBDVDPLAY_BUILDLINK3_MK

.include "../../multimedia/libdvdread/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
