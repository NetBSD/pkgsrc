# $NetBSD: buildlink3.mk,v 1.34 2021/06/24 20:17:31 markd Exp $

BUILDLINK_TREE+=	akonadi

.if !defined(AKONADI_BUILDLINK3_MK)
AKONADI_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.akonadi+=	akonadi>=0.82.0
BUILDLINK_ABI_DEPENDS.akonadi+=	akonadi>=1.13.0nb34
BUILDLINK_PKGSRCDIR.akonadi?=	../../mail/akonadi

BUILDLINK_FILES.akonadi+=	share/config/akonadi/*.conf
BUILDLINK_FILES.akonadi+=	share/dbus-1/interfaces/org.freedesktop.Akonadi.*.xml

.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.endif # AKONADI_BUILDLINK3_MK

BUILDLINK_TREE+=	-akonadi
