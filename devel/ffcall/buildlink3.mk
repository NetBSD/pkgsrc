# $NetBSD: buildlink3.mk,v 1.1 2004/03/02 16:05:01 adam Exp $
#
# This Makefile fragment is included by packages that use ffcall.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
FFCALL_BUILDLINK3_MK:=	${FFCALL_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ffcall
.endif

.if !empty(FFCALL_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			ffcall
BUILDLINK_DEPENDS.ffcall+=		ffcall>=1.9
BUILDLINK_PKGSRCDIR.ffcall?=		../../devel/ffcall

.endif # FFCALL_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
