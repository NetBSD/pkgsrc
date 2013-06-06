# $NetBSD: buildlink3.mk,v 1.31 2013/06/06 12:53:49 wiz Exp $

BUILDLINK_TREE+=	gconfmm

.if !defined(GCONFMM_BUILDLINK3_MK)
GCONFMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gconfmm+=	gconfmm>=2.10.0
BUILDLINK_ABI_DEPENDS.gconfmm+=	gconfmm>=2.28.3nb13
BUILDLINK_PKGSRCDIR.gconfmm?=	../../devel/gconfmm

.include "../../devel/GConf/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.endif # GCONFMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-gconfmm
