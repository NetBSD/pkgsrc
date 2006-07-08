# $NetBSD: buildlink3.mk,v 1.8 2006/07/08 23:10:43 jlam Exp $

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH}+
GLIBMM_BUILDLINK3_MK:=	${GLIBMM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	glibmm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nglibmm}
BUILDLINK_PACKAGES+=	glibmm
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}glibmm

.if !empty(GLIBMM_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.glibmm+=	glibmm>=2.6.1
BUILDLINK_ABI_DEPENDS.glibmm+=	glibmm>=2.8.3nb1
BUILDLINK_PKGSRCDIR.glibmm?=	../../devel/glibmm
.endif	# GLIBMM_BUILDLINK3_MK

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libsigc++2/buildlink3.mk"

BUILDLINK_DEPTH:=	${BUILDLINK_DEPTH:S/+$//}
