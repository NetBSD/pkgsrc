# $NetBSD: buildlink3.mk,v 1.1 2004/02/11 08:55:58 xtraeme Exp $
#
# This Makefile fragment is included by packages that use Hermes.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
HERMES_BUILDLINK3_MK:=	${HERMES_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	Hermes
.endif

.if !empty(HERMES_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=			Hermes
BUILDLINK_DEPENDS.Hermes+=		Hermes>=1.3.2
BUILDLINK_PKGSRCDIR.Hermes?=		../../graphics/hermes

.endif # HERMES_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
