# $NetBSD: buildlink3.mk,v 1.54 2023/04/19 08:08:16 adam Exp $

BUILDLINK_TREE+=	libglademm

.if !defined(LIBGLADEMM_BUILDLINK3_MK)
LIBGLADEMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libglademm+=	libglademm>=2.6.0
BUILDLINK_ABI_DEPENDS.libglademm+=	libglademm>=2.6.7nb44
BUILDLINK_PKGSRCDIR.libglademm?=	../../devel/libglademm

.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.endif # LIBGLADEMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libglademm
