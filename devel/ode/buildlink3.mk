# $NetBSD: buildlink3.mk,v 1.1 2004/02/27 07:56:33 xtraeme Exp $
#
# This Makefile fragment is included by packages that use ode.
#
# This file was created automatically using createbuildlink-3.1.
#

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
ODE_BUILDLINK3_MK:=	${ODE_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	ode
.endif

.if !empty(ODE_BUILDLINK3_MK:M+)
BUILDLINK_PACKAGES+=		ode
BUILDLINK_DEPENDS.ode+=		ode>=0.039
BUILDLINK_PKGSRCDIR.ode?=	../../devel/ode

.endif # ODE_BUILDLINK3_MK

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
