# $NetBSD: buildlink3.mk,v 1.1 2004/02/27 07:37:04 xtraeme Exp $
#
# This Makefile fragment is included by packages that use pnetC.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PNETC_BUILDLINK3_MK:=	${PNETC_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pnetC
.endif

.if !empty(PNETC_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			pnetC
BUILDLINK_DEPENDS.pnetC+=		pnetC>=0.6.0
BUILDLINK_PKGSRCDIR.pnetC?=		../../lang/pnetC

.include "../../lang/pnet/buildlink3.mk"

.endif # PNETC_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
