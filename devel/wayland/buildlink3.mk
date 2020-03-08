# $NetBSD: buildlink3.mk,v 1.2 2020/03/08 16:42:26 bsiegert Exp $

BUILDLINK_TREE+=	wayland

.if !defined(WAYLAND_BUILDLINK3_MK)
WAYLAND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wayland+=	wayland>=1.9.90
BUILDLINK_ABI_DEPENDS.wayland?=	wayland>=1.17.0nb5
BUILDLINK_PKGSRCDIR.wayland?=	../../devel/wayland

.include "../../devel/libffi/buildlink3.mk"
.endif	# WAYLAND_BUILDLINK3_MK

BUILDLINK_TREE+=	-wayland
