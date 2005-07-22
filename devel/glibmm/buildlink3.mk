# $NetBSD: buildlink3.mk,v 1.1.1.1 2005/07/22 21:12:20 adam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GLIBMM_BUILDLINK3_MK:=	${GLIBMM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	glibmm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nglibmm}
BUILDLINK_PACKAGES+=	glibmm

.if !empty(GLIBMM_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.glibmm+=	glibmm>=2.6.1
BUILDLINK_PKGSRCDIR.glibmm?=	../../devel/glibmm
.endif	# GLIBMM_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libsigc++2/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
