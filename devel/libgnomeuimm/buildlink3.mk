# $NetBSD: buildlink3.mk,v 1.43 2014/01/01 11:52:08 wiz Exp $

BUILDLINK_TREE+=	libgnomeuimm

.if !defined(LIBGNOMEUIMM_BUILDLINK3_MK)
LIBGNOMEUIMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgnomeuimm+=	libgnomeuimm>=2.10.0
BUILDLINK_ABI_DEPENDS.libgnomeuimm+=	libgnomeuimm>=2.28.0nb28
BUILDLINK_PKGSRCDIR.libgnomeuimm?=	../../devel/libgnomeuimm

.include "../../devel/gconfmm/buildlink3.mk"
.include "../../devel/libglademm/buildlink3.mk"
.include "../../devel/libgnomemm/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/libgnomecanvasmm/buildlink3.mk"
.include "../../sysutils/gnome-vfsmm/buildlink3.mk"
.endif # LIBGNOMEUIMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgnomeuimm
