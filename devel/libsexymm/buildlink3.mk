# $NetBSD: buildlink3.mk,v 1.7 2011/01/13 13:36:24 wiz Exp $

BUILDLINK_TREE+=	libsexymm

.if !defined(LIBSEXYMM_BUILDLINK3_MK)
LIBSEXYMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsexymm+=	libsexymm>=0.1.9
BUILDLINK_ABI_DEPENDS.libsexymm?=	libsexymm>=0.1.9nb6
BUILDLINK_PKGSRCDIR.libsexymm?=	../../devel/libsexymm

.include "../../x11/gtkmm/buildlink3.mk"
.include "../../devel/libsexy/buildlink3.mk"
.endif # LIBSEXYMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsexymm
