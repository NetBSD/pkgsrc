# $NetBSD: buildlink3.mk,v 1.2 2004/10/03 00:13:16 tv Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBMAL_BUILDLINK3_MK:=	${LIBMAL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libmal
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibmal}
BUILDLINK_PACKAGES+=	libmal

.if !empty(LIBMAL_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libmal+=	libmal>=0.40
BUILDLINK_RECOMMENDED.libmal+=	libmal>=0.40nb1
BUILDLINK_PKGSRCDIR.libmal?=	../../comms/libmal
.endif	# LIBMAL_BUILDLINK3_MK

.include "../../comms/pilot-link-libs/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
