# $NetBSD: buildlink3.mk,v 1.1.1.1 2004/03/05 14:46:23 adam Exp $
#
# This Makefile fragment is included by packages that use cln.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
CLN_BUILDLINK3_MK:=	${CLN_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	cln
.endif

.if !empty(CLN_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			cln
BUILDLINK_DEPENDS.cln+=		cln>=1.1.6
BUILDLINK_PKGSRCDIR.cln?=		../../adam/cln

.endif # CLN_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
