# $NetBSD: buildlink3.mk,v 1.7 2009/03/20 19:24:44 joerg Exp $

BUILDLINK_TREE+=	plotutils-nox11

.if !defined(PLOTUTILS_NOX11_BUILDLINK3_MK)
PLOTUTILS_NOX11_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.plotutils-nox11+=	plotutils-nox11>=2.4.1
BUILDLINK_ABI_DEPENDS.plotutils-nox11?=	plotutils-nox11>=2.4.1nb2
BUILDLINK_PKGSRCDIR.plotutils-nox11?=	../../graphics/plotutils-nox11

.include "../../graphics/png/buildlink3.mk"
.endif # PLOTUTILS_NOX11_BUILDLINK3_MK

BUILDLINK_TREE+=	-plotutils-nox11
