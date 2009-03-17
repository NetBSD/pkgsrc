# $NetBSD: buildlink3.mk,v 1.2 2009/03/17 22:10:15 jmcneill Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
PANGOMM_BUILDLINK3_MK:=	${PANGOMM_BUILDLINK3_MK}+

.if ${BUILDLINK_DEPTH} == "+"
BUILDLINK_DEPENDS+=	pangomm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Npangomm}
BUILDLINK_PACKAGES+=	pangomm
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}pangomm

.if ${PANGOMM_BUILDLINK3_MK} == "+"
BUILDLINK_API_DEPENDS.pangomm+=	pangomm>=2.24.0
BUILDLINK_PKGSRCDIR.pangomm?=	../../devel/pangomm
.endif	# PANGOMM_BUILDLINK3_MK

.include "../../devel/glibmm/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairomm/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
