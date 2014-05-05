# $NetBSD: buildlink3.mk,v 1.32 2014/05/05 00:47:44 ryoon Exp $

BUILDLINK_TREE+=	libglademm

.if !defined(LIBGLADEMM_BUILDLINK3_MK)
LIBGLADEMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libglademm+=	libglademm>=2.6.0
BUILDLINK_ABI_DEPENDS.libglademm+=	libglademm>=2.6.7nb21
BUILDLINK_PKGSRCDIR.libglademm?=	../../devel/libglademm

.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.endif # LIBGLADEMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libglademm
