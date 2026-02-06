# $NetBSD: buildlink3.mk,v 1.4 2026/02/06 10:04:35 wiz Exp $

BUILDLINK_TREE+=	plasma6-plasma5support

.if !defined(PLASMA6_PLASMA5SUPPORT_BUILDLINK3_MK)
PLASMA6_PLASMA5SUPPORT_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.plasma6-plasma5support+=	plasma6-plasma5support>=6.5.2
BUILDLINK_ABI_DEPENDS.plasma6-plasma5support?=	plasma6-plasma5support>=6.5.2nb3
BUILDLINK_PKGSRCDIR.plasma6-plasma5support?=	../../devel/plasma6-plasma5support

.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/kf6-kidletime/buildlink3.mk"
.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../devel/kf6-knotifications/buildlink3.mk"
.include "../../devel/kf6-kservice/buildlink3.mk"
.include "../../misc/kf6-kunitconversion/buildlink3.mk"
.include "../../time/kf6-kholidays/buildlink3.mk"
.include "../../sysutils/kf6-solid/buildlink3.mk"
.include "../../sysutils/plasma6-libksysguard/buildlink3.mk"
.include "../../x11/kf6-kguiaddons/buildlink3.mk"
.include "../../x11/plasma6-plasma-activities/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# PLASMA6_PLASMA5SUPPORT_BUILDLINK3_MK

BUILDLINK_TREE+=	-plasma6-plasma5support
