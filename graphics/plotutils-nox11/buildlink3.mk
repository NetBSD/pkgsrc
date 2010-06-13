# $NetBSD: buildlink3.mk,v 1.8 2010/06/13 22:44:41 wiz Exp $

BUILDLINK_TREE+=	plotutils-nox11

.if !defined(PLOTUTILS_NOX11_BUILDLINK3_MK)
PLOTUTILS_NOX11_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.plotutils-nox11+=	plotutils-nox11>=2.4.1
BUILDLINK_ABI_DEPENDS.plotutils-nox11?=	plotutils-nox11>=2.4.1nb3
BUILDLINK_PKGSRCDIR.plotutils-nox11?=	../../graphics/plotutils-nox11

.include "../../graphics/png/buildlink3.mk"
.endif # PLOTUTILS_NOX11_BUILDLINK3_MK

BUILDLINK_TREE+=	-plotutils-nox11
