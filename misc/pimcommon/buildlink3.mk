# $NetBSD: buildlink3.mk,v 1.9 2024/11/01 12:53:38 wiz Exp $

BUILDLINK_TREE+=	pimcommon

.if !defined(PIMCOMMON_BUILDLINK3_MK)
PIMCOMMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.pimcommon+=	pimcommon>=17.12.1
BUILDLINK_ABI_DEPENDS.pimcommon?=		pimcommon>=23.08.4nb5
BUILDLINK_PKGSRCDIR.pimcommon?=		../../misc/pimcommon

.include "../../mail/kimap/buildlink3.mk"
.include "../../misc/libkdepim/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../textproc/kpimtextedit/buildlink3.mk"
.include "../../textproc/ktextaddons/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# PIMCOMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-pimcommon
