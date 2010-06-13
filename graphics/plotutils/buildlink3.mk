# $NetBSD: buildlink3.mk,v 1.13 2010/06/13 22:44:41 wiz Exp $

BUILDLINK_TREE+=	plotutils

.if !defined(PLOTUTILS_BUILDLINK3_MK)
PLOTUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.plotutils+=	plotutils>=2.4.1nb2
BUILDLINK_ABI_DEPENDS.plotutils+=	plotutils>=2.6nb1
BUILDLINK_PKGSRCDIR.plotutils?=	../../graphics/plotutils

.include "../../graphics/png/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.endif # PLOTUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-plotutils
