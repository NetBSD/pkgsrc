# $NetBSD: buildlink3.mk,v 1.1 2004/02/27 07:37:04 xtraeme Exp $
#
# This Makefile fragment is included by packages that use pnet.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PNET_BUILDLINK3_MK:=	${PNET_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	pnet
.endif

.if !empty(PNET_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			pnet
BUILDLINK_DEPENDS.pnet+=		pnet>=0.6.2
BUILDLINK_PKGSRCDIR.pnet?=		../../lang/pnet

.endif # PNET_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
