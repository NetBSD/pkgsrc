# $NetBSD: buildlink3.mk,v 1.1 2004/02/19 01:49:18 wiz Exp $
#
# This Makefile fragment is included by packages that use speex.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
SPEEX_BUILDLINK3_MK:=	${SPEEX_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	speex
.endif

.if !empty(SPEEX_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			speex
BUILDLINK_DEPENDS.speex+=		speex>=1.0.2nb1
BUILDLINK_PKGSRCDIR.speex?=		../../audio/speex

.include "../../audio/libogg/buildlink3.mk"

.endif # SPEEX_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
