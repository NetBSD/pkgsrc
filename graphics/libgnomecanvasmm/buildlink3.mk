# $NetBSD: buildlink3.mk,v 1.8 2006/07/08 23:10:52 jlam Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
LIBGNOMECANVASMM_BUILDLINK3_MK:=	${LIBGNOMECANVASMM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgnomecanvasmm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgnomecanvasmm}
BUILDLINK_PACKAGES+=	libgnomecanvasmm
BUILDLINK_ORDER:=	${BUILDLINK_ORDER} ${BUILDLINK_DEPTH}libgnomecanvasmm

.if !empty(LIBGNOMECANVASMM_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libgnomecanvasmm+=	libgnomecanvasmm>=2.10.0
BUILDLINK_ABI_DEPENDS.libgnomecanvasmm?=	libgnomecanvasmm>=2.14.0nb1
BUILDLINK_PKGSRCDIR.libgnomecanvasmm?=	../../graphics/libgnomecanvasmm
.endif	# LIBGNOMECANVASMM_BUILDLINK3_MK

.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
