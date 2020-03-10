# $NetBSD: buildlink3.mk,v 1.4 2020/03/10 22:08:43 wiz Exp $

BUILDLINK_TREE+=	kwayland

.if !defined(KWAYLAND_BUILDLINK3_MK)
KWAYLAND_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kwayland+=	kwayland>=5.6.3
BUILDLINK_ABI_DEPENDS.kwayland?=		kwayland>=5.66.0nb2
BUILDLINK_PKGSRCDIR.kwayland?=		../../devel/kwayland

.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KWAYLAND_BUILDLINK3_MK

BUILDLINK_TREE+=	-kwayland
