# $NetBSD: buildlink3.mk,v 1.2 2023/10/24 22:09:54 wiz Exp $

BUILDLINK_TREE+=	akonadi-notes

.if !defined(AKONADI_NOTES_BUILDLINK3_MK)
AKONADI_NOTES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.akonadi-notes+=	akonadi-notes>=17.12.1
BUILDLINK_ABI_DEPENDS.akonadi-notes?=	akonadi-notes>=23.04.3nb1
BUILDLINK_PKGSRCDIR.akonadi-notes?=	../../misc/akonadi-notes

.include "../../mail/kmime/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# AKONADI_NOTES_BUILDLINK3_MK

BUILDLINK_TREE+=	-akonadi-notes
