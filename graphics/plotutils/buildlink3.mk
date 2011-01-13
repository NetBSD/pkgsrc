# $NetBSD: buildlink3.mk,v 1.14 2011/01/13 13:36:05 wiz Exp $

BUILDLINK_TREE+=	plotutils

.if !defined(PLOTUTILS_BUILDLINK3_MK)
PLOTUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.plotutils+=	plotutils>=2.4.1nb2
BUILDLINK_ABI_DEPENDS.plotutils+=	plotutils>=2.6nb2
BUILDLINK_PKGSRCDIR.plotutils?=	../../graphics/plotutils

.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.endif # PLOTUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-plotutils
