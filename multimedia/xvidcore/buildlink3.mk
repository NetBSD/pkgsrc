# $NetBSD: buildlink3.mk,v 1.1 2004/02/20 17:23:44 jmmv Exp $
#
# This Makefile fragment is included by packages that use xvidcore.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
XVIDCORE_BUILDLINK3_MK:=	${XVIDCORE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	xvidcore
.endif

.if !empty(XVIDCORE_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			xvidcore
BUILDLINK_DEPENDS.xvidcore+=		xvidcore>=0.9.1
BUILDLINK_PKGSRCDIR.xvidcore?=		../../multimedia/xvidcore

.endif # XVIDCORE_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
