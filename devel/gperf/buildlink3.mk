# $NetBSD: buildlink3.mk,v 1.1 2004/02/17 13:15:54 dmcmahill Exp $
#
# This Makefile fragment is included by packages that use gperf.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GPERF_BUILDLINK3_MK:=	${GPERF_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gperf
.endif

.if !empty(GPERF_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			gperf
BUILDLINK_DEPENDS.gperf+=		gperf>=3.0.1
BUILDLINK_PKGSRCDIR.gperf?=		../../devel/gperf

BUILDLINK_DEPMETHOD.gperf=		build

.endif # GPERF_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
