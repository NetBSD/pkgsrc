# $NetBSD: buildlink3.mk,v 1.17 2026/01/27 08:40:07 wiz Exp $

BUILDLINK_TREE+=	akonadi-search

.if !defined(AKONADI_SEARCH_BUILDLINK3_MK)
AKONADI_SEARCH_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.akonadi-search+=	akonadi-search>=25.08.2
BUILDLINK_ABI_DEPENDS.akonadi-search?=	akonadi-search>=25.08.3nb2
BUILDLINK_PKGSRCDIR.akonadi-search?=	../../misc/akonadi-search

.include "../../devel/kf6-kcmutils/buildlink3.mk"
.include "../../devel/kf6-krunner/buildlink3.mk"
.include "../../mail/akonadi-mime/buildlink3.mk"
.include "../../misc/kf6-kcontacts/buildlink3.mk"
.include "../../textproc/ktextaddons/buildlink3.mk"
.include "../../textproc/xapian/buildlink3.mk"
.include "../../time/kf6-kcalendarcore/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# AKONADI_SEARCH_BUILDLINK3_MK

BUILDLINK_TREE+=	-akonadi-search
