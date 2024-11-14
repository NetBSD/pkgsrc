# $NetBSD: buildlink3.mk,v 1.8 2024/11/14 22:20:44 wiz Exp $

BUILDLINK_TREE+=	akonadi-notes

.if !defined(AKONADI_NOTES_BUILDLINK3_MK)
AKONADI_NOTES_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.akonadi-notes+=	akonadi-notes>=17.12.1
BUILDLINK_ABI_DEPENDS.akonadi-notes?=	akonadi-notes>=23.08.4nb6
BUILDLINK_PKGSRCDIR.akonadi-notes?=	../../misc/akonadi-notes

.include "../../mail/kmime/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# AKONADI_NOTES_BUILDLINK3_MK

BUILDLINK_TREE+=	-akonadi-notes
