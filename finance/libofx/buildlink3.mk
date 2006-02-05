# $NetBSD: buildlink3.mk,v 1.1.1.1 2006/02/05 22:25:01 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBOFX_BUILDLINK3_MK:=	${OPENSP_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libofx
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibofx}
BUILDLINK_PACKAGES+=	libofx

.if !empty(LIBOFX_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libofx+=	libofx>=0.8.0
BUILDLINK_PKGSRCDIR.libofx?=	../../finance/libofx
.endif	# LIBOFX_BUILDLINK3_MK

BUILDLINK_INCDIRS.libofx+=    include/libofx

.include "../../textproc/opensp/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
