# $NetBSD: buildlink3.mk,v 1.7 2024/08/09 09:42:20 ryoon Exp $

BUILDLINK_TREE+=	akonadi-import-wizard

.if !defined(AKONADI_IMPORT_WIZARD_BUILDLINK3_MK)
AKONADI_IMPORT_WIZARD_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.akonadi-import-wizard+=	akonadi-import-wizard>=20.04.1
BUILDLINK_ABI_DEPENDS.akonadi-import-wizard?=	akonadi-import-wizard>=23.08.4nb3
BUILDLINK_PKGSRCDIR.akonadi-import-wizard?=	../../mail/akonadi-import-wizard

.include "../../mail/mailcommon/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# AKONADI_IMPORT_WIZARD_BUILDLINK3_MK

BUILDLINK_TREE+=	-akonadi-import-wizard
