# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/02/26 12:49:23 jmmv Exp $
#
# This Makefile fragment is included by packages that use openobex.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
OPENOBEX_BUILDLINK3_MK:=	${OPENOBEX_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	openobex
.endif

.if !empty(OPENOBEX_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			openobex
BUILDLINK_DEPENDS.openobex+=		openobex>=1.0.1
BUILDLINK_PKGSRCDIR.openobex?=		../../comms/openobex

.endif # OPENOBEX_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
