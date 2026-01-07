# $NetBSD: buildlink3.mk,v 1.16 2026/01/07 08:48:01 wiz Exp $

BUILDLINK_TREE+=	libgravatar

.if !defined(LIBGRAVATAR_BUILDLINK3_MK)
LIBGRAVATAR_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.libgravatar+=	libgravatar>=25.08.3
BUILDLINK_ABI_DEPENDS.libgravatar?=	libgravatar>=25.08.3nb1
BUILDLINK_PKGSRCDIR.libgravatar?=	../../misc/libgravatar

.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../x11/kf6-kconfigwidgets/buildlink3.mk"
.include "../../x11/kf6-kwidgetsaddons/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# LIBGRAVATAR_BUILDLINK3_MK

BUILDLINK_TREE+=	-libgravatar
