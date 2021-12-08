# $NetBSD: buildlink3.mk,v 1.3 2021/12/08 16:02:04 adam Exp $

BUILDLINK_TREE+=	wayland

.if !defined(WAYLAND_BUILDLINK3_MK)
WAYLAND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wayland+=	wayland>=1.9.90
BUILDLINK_ABI_DEPENDS.wayland?=	wayland>=1.18.0nb3
BUILDLINK_PKGSRCDIR.wayland?=	../../devel/wayland

.include "../../devel/libffi/buildlink3.mk"
.endif	# WAYLAND_BUILDLINK3_MK

BUILDLINK_TREE+=	-wayland
