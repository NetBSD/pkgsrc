# $NetBSD: buildlink3.mk,v 1.22 2013/09/02 19:50:40 adam Exp $

BUILDLINK_TREE+=	libsexymm

.if !defined(LIBSEXYMM_BUILDLINK3_MK)
LIBSEXYMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsexymm+=	libsexymm>=0.1.9
BUILDLINK_ABI_DEPENDS.libsexymm+=	libsexymm>=0.1.9nb20
BUILDLINK_PKGSRCDIR.libsexymm?=	../../devel/libsexymm

.include "../../x11/gtkmm/buildlink3.mk"
.include "../../devel/libsexy/buildlink3.mk"
.endif # LIBSEXYMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsexymm
