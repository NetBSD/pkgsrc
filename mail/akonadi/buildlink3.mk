# $NetBSD: buildlink3.mk,v 1.55 2026/02/06 10:05:10 wiz Exp $

BUILDLINK_TREE+=	akonadi

.if !defined(AKONADI_BUILDLINK3_MK)
AKONADI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.akonadi+=	akonadi>=25.08.2
BUILDLINK_ABI_DEPENDS.akonadi?=	akonadi>=25.08.3nb3
BUILDLINK_PKGSRCDIR.akonadi?=	../../mail/akonadi

BUILDLINK_FILES.akonadi+=	share/dbus-1/interfaces/org.freedesktop.Akonadi.*.xml
BUILDLINK_FILES.akonadi+=	share/kf6/akonadi/kcfg2dbus.xsl

.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../devel/kf6-kitemmodels/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# AKONADI_BUILDLINK3_MK

BUILDLINK_TREE+=	-akonadi
