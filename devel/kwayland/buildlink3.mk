# $NetBSD: buildlink3.mk,v 1.6 2020/06/02 08:22:38 adam Exp $

BUILDLINK_TREE+=	kwayland

.if !defined(KWAYLAND_BUILDLINK3_MK)
KWAYLAND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kwayland+=	kwayland>=5.6.3
BUILDLINK_ABI_DEPENDS.kwayland?=		kwayland>=5.66.0nb4
BUILDLINK_PKGSRCDIR.kwayland?=		../../devel/kwayland

.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KWAYLAND_BUILDLINK3_MK

BUILDLINK_TREE+=	-kwayland
