# $NetBSD: buildlink3.mk,v 1.1 2004/04/12 05:11:44 snj Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GCONFMM_BUILDLINK3_MK:=	${GCONFMM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	gconfmm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Ngconfmm}
BUILDLINK_PACKAGES+=	gconfmm

.if !empty(GCONFMM_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.gconfmm+=	gconfmm>=2.0.1nb5
BUILDLINK_PKGSRCDIR.gconfmm?=	../../devel/gconfmm
.endif	# GCONFMM_BUILDLINK3_MK

.include "../../devel/GConf2/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
