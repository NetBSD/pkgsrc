# $NetBSD: buildlink3.mk,v 1.14 2010/11/15 22:57:22 abs Exp $

BUILDLINK_TREE+=	libgnomecanvasmm

.if !defined(LIBGNOMECANVASMM_BUILDLINK3_MK)
LIBGNOMECANVASMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgnomecanvasmm+=	libgnomecanvasmm>=2.10.0
BUILDLINK_ABI_DEPENDS.libgnomecanvasmm+=	libgnomecanvasmm>=2.26.0nb4
BUILDLINK_PKGSRCDIR.libgnomecanvasmm?=	../../graphics/libgnomecanvasmm

.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.endif # LIBGNOMECANVASMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgnomecanvasmm
