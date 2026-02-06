# $NetBSD: buildlink3.mk,v 1.17 2026/02/06 10:05:22 wiz Exp $

BUILDLINK_TREE+=	libkdepim

.if !defined(LIBKDEPIM_BUILDLINK3_MK)
LIBKDEPIM_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libkdepim+=	libkdepim>=25.08.2
BUILDLINK_ABI_DEPENDS.libkdepim?=	libkdepim>=25.08.3nb2
BUILDLINK_PKGSRCDIR.libkdepim?=		../../misc/libkdepim

BUILDLINK_FILES.libkdepim+=	share/dbus-1/interfaces/org.kde.*.xml

.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../textproc/kf6-kcompletion/buildlink3.mk"
.include "../../x11/kf6-kwidgetsaddons/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# LIBKDEPIM_BUILDLINK3_MK

BUILDLINK_TREE+=	-libkdepim
