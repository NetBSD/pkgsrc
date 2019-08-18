# $NetBSD: buildlink3.mk,v 1.1 2019/08/18 16:07:12 nia Exp $

BUILDLINK_TREE+=	wayland-protocols

.if !defined(WAYLAND_PROTOCOLS_BUILDLINK3_MK)
WAYLAND_PROTOCOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wayland-protocols+=	wayland-protocols>=1.17
BUILDLINK_PKGSRCDIR.wayland-protocols?=		../../devel/wayland-protocols

.endif	# WAYLAND_PROTOCOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-wayland-protocols
