# $NetBSD: buildlink3.mk,v 1.4 2022/08/04 15:21:26 nia Exp $

BUILDLINK_TREE+=	wayland

.if !defined(WAYLAND_BUILDLINK3_MK)
WAYLAND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wayland+=	wayland>=1.9.90
BUILDLINK_ABI_DEPENDS.wayland?=	wayland>=1.18.0nb3
BUILDLINK_PKGSRCDIR.wayland?=	../../devel/wayland

.include "../../mk/bsd.fast.prefs.mk"
.if ${OPSYS} != "Linux"
.  include "../../devel/libepoll-shim/buildlink3.mk"
.endif
.include "../../devel/libffi/buildlink3.mk"
.endif	# WAYLAND_BUILDLINK3_MK

BUILDLINK_TREE+=	-wayland
