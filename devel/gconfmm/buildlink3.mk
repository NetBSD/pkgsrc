# $NetBSD: buildlink3.mk,v 1.12 2007/09/21 13:03:35 wiz Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GCONFMM_BUILDLINK3_MK:=	${GCONFMM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gconfmm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngconfmm}
BUILDLINK_PACKAGES+=	gconfmm
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}gconfmm

.if !empty(GCONFMM_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gconfmm+=	gconfmm>=2.10.0
BUILDLINK_ABI_DEPENDS.gconfmm+=	gconfmm>=2.14.0nb1
BUILDLINK_PKGSRCDIR.gconfmm?=	../../devel/gconfmm
.endif	# GCONFMM_BUILDLINK3_MK

.include "../../devel/GConf/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
