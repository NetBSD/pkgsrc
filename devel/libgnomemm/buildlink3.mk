# $NetBSD: buildlink3.mk,v 1.72 2023/11/12 13:21:05 wiz Exp $

BUILDLINK_TREE+=	libgnomemm

.if !defined(LIBGNOMEMM_BUILDLINK3_MK)
LIBGNOMEMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgnomemm+=	libgnomemm>=2.10.0
BUILDLINK_ABI_DEPENDS.libgnomemm+=	libgnomemm>=2.30.0nb53
BUILDLINK_PKGSRCDIR.libgnomemm?=	../../devel/libgnomemm

.include "../../devel/libgnome/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.endif # LIBGNOMEMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgnomemm
