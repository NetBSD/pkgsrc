# $NetBSD: buildlink3.mk,v 1.1 2004/02/15 20:01:11 wiz Exp $
#
# This Makefile fragment is included by packages that use fribidi.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
FRIBIDI_BUILDLINK3_MK:=	${FRIBIDI_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	fribidi
.endif

.if !empty(FRIBIDI_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			fribidi
BUILDLINK_DEPENDS.fribidi+=		fribidi>=0.10.4
BUILDLINK_PKGSRCDIR.fribidi?=		../../converters/fribidi

.endif # FRIBIDI_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
