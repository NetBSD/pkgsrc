# $NetBSD: buildlink3.mk,v 1.1 2004/02/19 10:59:28 wiz Exp $
#
# This Makefile fragment is included by packages that use libcomprex.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBCOMPREX_BUILDLINK3_MK:=	${LIBCOMPREX_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libcomprex
.endif

.if !empty(LIBCOMPREX_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libcomprex
BUILDLINK_DEPENDS.libcomprex+=		libcomprex>=0.3.2
BUILDLINK_PKGSRCDIR.libcomprex?=		../../archivers/libcomprex

.include "../../www/curl/buildlink3.mk"

.endif # LIBCOMPREX_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
