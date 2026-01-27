# $NetBSD: buildlink3.mk,v 1.17 2026/01/27 08:40:01 wiz Exp $

BUILDLINK_TREE+=	akonadi-import-wizard

.if !defined(AKONADI_IMPORT_WIZARD_BUILDLINK3_MK)
AKONADI_IMPORT_WIZARD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.akonadi-import-wizard+=	akonadi-import-wizard>=20.04.1
BUILDLINK_ABI_DEPENDS.akonadi-import-wizard?=	akonadi-import-wizard>=25.08.3nb2
BUILDLINK_PKGSRCDIR.akonadi-import-wizard?=	../../mail/akonadi-import-wizard

.include "../../mail/mailcommon/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# AKONADI_IMPORT_WIZARD_BUILDLINK3_MK

BUILDLINK_TREE+=	-akonadi-import-wizard
