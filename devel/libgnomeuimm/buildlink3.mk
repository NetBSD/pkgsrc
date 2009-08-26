# $NetBSD: buildlink3.mk,v 1.16 2009/08/26 19:56:46 sno Exp $

BUILDLINK_TREE+=	libgnomeuimm

.if !defined(LIBGNOMEUIMM_BUILDLINK3_MK)
LIBGNOMEUIMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgnomeuimm+=	libgnomeuimm>=2.10.0
BUILDLINK_ABI_DEPENDS.libgnomeuimm+=	libgnomeuimm>=2.26.0nb1
BUILDLINK_PKGSRCDIR.libgnomeuimm?=	../../devel/libgnomeuimm

.include "../../devel/gconfmm/buildlink3.mk"
.include "../../devel/libglademm/buildlink3.mk"
.include "../../devel/libgnomemm/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/libgnomecanvasmm/buildlink3.mk"
.include "../../sysutils/gnome-vfsmm/buildlink3.mk"
.endif # LIBGNOMEUIMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgnomeuimm
