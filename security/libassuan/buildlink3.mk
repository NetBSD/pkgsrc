# $NetBSD: buildlink3.mk,v 1.2 2006/02/05 23:10:44 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBASSUAN_BUILDLINK3_MK:=	${LIBASSUAN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libassuan
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibassuan}
BUILDLINK_PACKAGES+=	libassuan

.if !empty(LIBASSUAN_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libassuan+=	libassuan>=0.6.7
BUILDLINK_RECOMMENDED.libassuan?=	libassuan>=0.6.10nb2
BUILDLINK_PKGSRCDIR.libassuan?=	../../security/libassuan
.endif	# LIBASSUAN_BUILDLINK3_MK

.include "../../security/libgpg-error/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
