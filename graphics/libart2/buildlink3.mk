# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 01:25:25 xtraeme Exp $
#
# This Makefile fragment is included by packages that use libart2.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBART2_BUILDLINK3_MK:=	${LIBART2_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libart2
.endif

.if !empty(LIBART2_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			libart2
BUILDLINK_DEPENDS.libart2+=		libart2>=2.3.10nb1
BUILDLINK_PKGSRCDIR.libart2?=		../../graphics/libart2

.endif # LIBART2_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
