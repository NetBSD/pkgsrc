# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 08:44:23 xtraeme Exp $
#
# This Makefile fragment is included by packages that use aalib.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
AALIB_BUILDLINK3_MK:=	${AALIB_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	aalib
.endif

.if !empty(AALIB_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			aalib
BUILDLINK_DEPENDS.aalib+=		aalib>=1.4.0.4
BUILDLINK_PKGSRCDIR.aalib?=		../../graphics/aalib

.endif # AALIB_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
