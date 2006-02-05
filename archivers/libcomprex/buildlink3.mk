# $NetBSD: buildlink3.mk,v 1.6 2006/02/05 23:08:04 joerg Exp $

BUILDLINK_DEPTH:=		${BUILDLINK_DEPTH}+
LIBCOMPREX_BUILDLINK3_MK:=	${LIBCOMPREX_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libcomprex
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibcomprex}
BUILDLINK_PACKAGES+=	libcomprex

.if !empty(LIBCOMPREX_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libcomprex+=		libcomprex>=0.3.2
BUILDLINK_RECOMMENDED.libcomprex+=	libcomprex>=0.3.3nb1
BUILDLINK_PKGSRCDIR.libcomprex?=	../../archivers/libcomprex
.endif	# LIBCOMPREX_BUILDLINK3_MK

.include "../../www/curl/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
