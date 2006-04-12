# $NetBSD: buildlink3.mk,v 1.7 2006/04/12 10:27:08 rillig Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GCONFMM_BUILDLINK3_MK:=	${GCONFMM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gconfmm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngconfmm}
BUILDLINK_PACKAGES+=	gconfmm

.if !empty(GCONFMM_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.gconfmm+=	gconfmm>=2.10.0
BUILDLINK_ABI_DEPENDS.gconfmm?=	gconfmm>=2.12.0nb2
BUILDLINK_PKGSRCDIR.gconfmm?=	../../devel/gconfmm
.endif	# GCONFMM_BUILDLINK3_MK

.include "../../devel/GConf2/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
