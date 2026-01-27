# $NetBSD: buildlink3.mk,v 1.17 2026/01/27 08:40:01 wiz Exp $

BUILDLINK_TREE+=	akonadi-mime

.if !defined(AKONADI_MIME_BUILDLINK3_MK)
AKONADI_MIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.akonadi-mime+=	akonadi-mime>=25.08.2
BUILDLINK_ABI_DEPENDS.akonadi-mime?=	akonadi-mime>=25.08.3nb2
BUILDLINK_PKGSRCDIR.akonadi-mime?=	../../mail/akonadi-mime

.include "../../mail/akonadi/buildlink3.mk"
.include "../../mail/kmime/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# AKONADI_MIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-akonadi-mime
