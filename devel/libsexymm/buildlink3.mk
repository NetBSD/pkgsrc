# $NetBSD: buildlink3.mk,v 1.34 2019/07/21 22:24:02 wiz Exp $

BUILDLINK_TREE+=	libsexymm

.if !defined(LIBSEXYMM_BUILDLINK3_MK)
LIBSEXYMM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libsexymm+=	libsexymm>=0.1.9
BUILDLINK_ABI_DEPENDS.libsexymm+=	libsexymm>=0.1.9nb31
BUILDLINK_PKGSRCDIR.libsexymm?=		../../devel/libsexymm

.include "../../x11/gtkmm/buildlink3.mk"
.include "../../devel/libsexy/buildlink3.mk"
.endif # LIBSEXYMM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libsexymm
