# $NetBSD: buildlink3.mk,v 1.2 2004/03/05 19:25:06 jlam Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBCOMPREX_BUILDLINK3_MK:=	${LIBCOMPREX_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libcomprex
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibcomprex}
BUILDLINK_PACKAGES+=	libcomprex

.if !empty(LIBCOMPREX_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libcomprex+=		libcomprex>=0.3.2
BUILDLINK_PKGSRCDIR.libcomprex?=	../../archivers/libcomprex

.include "../../www/curl/buildlink3.mk"

.endif	# LIBCOMPREX_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
