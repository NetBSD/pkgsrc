# $NetBSD: buildlink3.mk,v 1.5 2006/04/12 10:27:18 rillig Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
LIBGNOMECANVASMM_BUILDLINK3_MK:=	${LIBGNOMECANVASMM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgnomecanvasmm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgnomecanvasmm}
BUILDLINK_PACKAGES+=	libgnomecanvasmm

.if !empty(LIBGNOMECANVASMM_BUILDLINK3_MK:M+)
BUILDLINK_API_DEPENDS.libgnomecanvasmm+=	libgnomecanvasmm>=2.10.0
BUILDLINK_ABI_DEPENDS.libgnomecanvasmm?=	libgnomecanvasmm>=2.12.0nb2
BUILDLINK_PKGSRCDIR.libgnomecanvasmm?=	../../graphics/libgnomecanvasmm
.endif	# LIBGNOMECANVASMM_BUILDLINK3_MK

.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH:S/+$//}
