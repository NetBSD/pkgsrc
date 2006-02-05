# $NetBSD: buildlink3.mk,v 1.3 2006/02/05 23:08:27 joerg Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBMAL_BUILDLINK3_MK:=	${LIBMAL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libmal
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibmal}
BUILDLINK_PACKAGES+=	libmal

.if !empty(LIBMAL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libmal+=	libmal>=0.40
BUILDLINK_RECOMMENDED.libmal+=	libmal>=0.40nb2
BUILDLINK_PKGSRCDIR.libmal?=	../../comms/libmal
.endif	# LIBMAL_BUILDLINK3_MK

.include "../../comms/pilot-link-libs/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
