# $NetBSD: buildlink3.mk,v 1.11 2026/11/25 14:42:03 wiz Exp $

BUILDLINK_TREE+=	ode

.if !defined(ODE_BUILDLINK3_MK)
ODE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.ode+=	ode>=0.13
BUILDLINK_PKGSRCDIR.ode?=	../../devel/ode

.include "../../mk/mesa.buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.endif	# ODE_BUILDLINK3_MK

BUILDLINK_TREE+=	-ode
