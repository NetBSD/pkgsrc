# $NetBSD: buildlink3.mk,v 1.33 2013/10/10 14:41:47 ryoon Exp $

BUILDLINK_TREE+=	gconfmm

.if !defined(GCONFMM_BUILDLINK3_MK)
GCONFMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gconfmm+=	gconfmm>=2.10.0
BUILDLINK_ABI_DEPENDS.gconfmm+=	gconfmm>=2.28.3nb15
BUILDLINK_PKGSRCDIR.gconfmm?=	../../devel/gconfmm

.include "../../devel/GConf/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.endif # GCONFMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-gconfmm
