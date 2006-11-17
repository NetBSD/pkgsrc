# $NetBSD: buildlink3.mk,v 1.7 2006/11/17 12:34:47 shannonjr Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBASSUAN_BUILDLINK3_MK:=	${LIBASSUAN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libassuan
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibassuan}
BUILDLINK_PACKAGES+=	libassuan
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libassuan

.if !empty(LIBASSUAN_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libassuan+=	libassuan>=1.0.0
BUILDLINK_ABI_DEPENDS.libassuan?=	libassuan>=1.0.0
BUILDLINK_PKGSRCDIR.libassuan?=	../../security/libassuan
.endif	# LIBASSUAN_BUILDLINK3_MK

.include "../../security/libgpg-error/buildlink3.mk"

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH:S/+$//}
