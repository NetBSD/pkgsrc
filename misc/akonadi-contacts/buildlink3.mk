# $NetBSD: buildlink3.mk,v 1.16 2026/01/07 08:47:54 wiz Exp $

BUILDLINK_TREE+=	akonadi-contacts

.if !defined(AKONADI_CONTACTS_BUILDLINK3_MK)
AKONADI_CONTACTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.akonadi-contacts+=	akonadi-contacts>=25.08.3
BUILDLINK_ABI_DEPENDS.akonadi-contacts?=	akonadi-contacts>=25.08.3nb1
BUILDLINK_PKGSRCDIR.akonadi-contacts?=		../../misc/akonadi-contacts

.include "../../devel/kf6-kcmutils/buildlink3.mk"
.include "../../graphics/kf6-prison/buildlink3.mk"
.include "../../mail/akonadi/buildlink3.mk"
.include "../../mail/kmime/buildlink3.mk"
.include "../../misc/grantleetheme/buildlink3.mk"
.include "../../misc/kf6-kcontacts/buildlink3.mk"
.include "../../textproc/ktextaddons/buildlink3.mk"
.include "../../x11/kf6-ktextwidgets/buildlink3.mk"
.include "../../x11/kf6-kxmlgui/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# AKONADI_CONTACTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-akonadi-contacts
