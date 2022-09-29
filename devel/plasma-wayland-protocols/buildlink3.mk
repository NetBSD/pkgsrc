# $NetBSD: buildlink3.mk,v 1.1 2022/09/29 15:37:11 ryoon Exp $

BUILDLINK_TREE+=	plasma-wayland-protocols

.if !defined(PLASMA_WAYLAND_PROTOCOLS_BUILDLINK3_MK)
PLASMA_WAYLAND_PROTOCOLS_BUILDLINK3_MK:=

.include "../../mk/bsd.fast.prefs.mk"
BUILDLINK_DEPMETHOD.plasma-wayland-protocols?=	build

BUILDLINK_API_DEPENDS.plasma-wayland-protocols+=	plasma-wayland-protocols>=1.9.0
BUILDLINK_PKGSRCDIR.plasma-wayland-protocols?=		../../devel/plasma-wayland-protocols
BUILDLINK_FILES.plasma-wayland-protocols+=		share/plasma-wayland-protocols/*.xml

.endif	# PLASMA_WAYLAND_PROTOCOLS_BUILDLINK3_MK

BUILDLINK_TREE+=	-plasma-wayland-protocols
