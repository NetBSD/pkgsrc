# $NetBSD: buildlink3.mk,v 1.2 2006/01/24 07:32:16 wiz Exp $

BUILDLINK_DEPTH:=			${BUILDLINK_DEPTH}+
LIBGNOMECANVASMM_BUILDLINK3_MK:=	${LIBGNOMECANVASMM_BUILDLINK3_MK}+

.if !empty(BUILDLINK_DEPTH:M+)
BUILDLINK_DEPENDS+=	libgnomecanvasmm
.endif

BUILDLINK_PACKAGES:=	${BUILDLINK_PACKAGES:Nlibgnomecanvasmm}
BUILDLINK_PACKAGES+=	libgnomecanvasmm

.if !empty(LIBGNOMECANVASMM_BUILDLINK3_MK:M+)
BUILDLINK_DEPENDS.libgnomecanvasmm+=	libgnomecanvasmm>=2.10.0
BUILDLINK_RECOMMENDED.libgnomecanvasmm?=	libgnomecanvasmm>=2.12.0nb1
BUILDLINK_PKGSRCDIR.libgnomecanvasmm?=	../../graphics/libgnomecanvasmm
.endif	# LIBGNOMECANVASMM_BUILDLINK3_MK

.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"

BUILDLINK_DEPTH:=     ${BUILDLINK_DEPTH:S/+$//}
