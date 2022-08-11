# $NetBSD: buildlink3.mk,v 1.2 2022/08/11 05:08:14 gutteridge Exp $

BUILDLINK_TREE+=	wayland-protocols

.if !defined(WAYLAND_PROTOCOLS_BUILDLINK3_MK)
WAYLAND_PROTOCOLS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.wayland-protocols+=	wayland-protocols>=1.17
BUILDLINK_ABI_DEPENDS.wayland-protocols?=		wayland-protocols>=1.26nb1
BUILDLINK_PKGSRCDIR.wayland-protocols?=		../../devel/wayland-protocols

.endif	# WAYLAND_PROTOCOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-wayland-protocols
