# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 08:37:35 xtraeme Exp $
#
# This Makefile fragment is included by packages that use liba52.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
LIBA52_BUILDLINK3_MK:=	${LIBA52_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	liba52
.endif

.if !empty(LIBA52_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			liba52
BUILDLINK_DEPENDS.liba52+=		liba52>=0.7.4
BUILDLINK_PKGSRCDIR.liba52?=		../../audio/liba52

.endif # LIBA52_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
