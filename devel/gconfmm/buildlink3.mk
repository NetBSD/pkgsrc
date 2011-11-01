# $NetBSD: buildlink3.mk,v 1.20 2011/11/01 06:00:55 sbd Exp $

BUILDLINK_TREE+=	gconfmm

.if !defined(GCONFMM_BUILDLINK3_MK)
GCONFMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.gconfmm+=	gconfmm>=2.10.0
BUILDLINK_ABI_DEPENDS.gconfmm+=	gconfmm>=2.28.2nb3
BUILDLINK_PKGSRCDIR.gconfmm?=	../../devel/gconfmm

.include "../../devel/GConf/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.endif # GCONFMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-gconfmm
