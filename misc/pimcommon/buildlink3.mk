# $NetBSD: buildlink3.mk,v 1.17 2026/01/27 08:40:13 wiz Exp $

BUILDLINK_TREE+=	pimcommon

.if !defined(PIMCOMMON_BUILDLINK3_MK)
PIMCOMMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pimcommon+=	pimcommon>=25.08.3
BUILDLINK_ABI_DEPENDS.pimcommon?=	pimcommon>=25.08.3nb2
BUILDLINK_PKGSRCDIR.pimcommon?=		../../misc/pimcommon

.include "../../databases/kldap/buildlink3.mk"
.include "../../devel/kf6-purpose/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../mail/kimap/buildlink3.mk"
.include "../../misc/akonadi-contacts/buildlink3.mk"
.include "../../misc/akonadi-search/buildlink3.mk"
.include "../../misc/libkdepim/buildlink3.mk"
.include "../../net/kf6-knewstuff/buildlink3.mk"
.include "../../textproc/ktextaddons/buildlink3.mk"
.include "../../x11/plasma6-plasma-activities/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# PIMCOMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-pimcommon
