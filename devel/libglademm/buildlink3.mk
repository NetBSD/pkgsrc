# $NetBSD: buildlink3.mk,v 1.11 2009/03/20 19:24:18 joerg Exp $

BUILDLINK_TREE+=	libglademm

.if !defined(LIBGLADEMM_BUILDLINK3_MK)
LIBGLADEMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libglademm+=	libglademm>=2.6.0
BUILDLINK_ABI_DEPENDS.libglademm+=	libglademm>=2.6.2nb1
BUILDLINK_PKGSRCDIR.libglademm?=	../../devel/libglademm

.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/gtkmm/buildlink3.mk"
.endif # LIBGLADEMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libglademm
