# $NetBSD: buildlink3.mk,v 1.22 2026/09/02 19:03:18 wiz Exp $

BUILDLINK_TREE+=	mailimporter

.if !defined(MAILIMPORTER_BUILDLINK3_MK)
MAILIMPORTER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mailimporter+=	mailimporter>=25.08.3
BUILDLINK_ABI_DEPENDS.mailimporter?=	mailimporter>=25.08.3nb7
BUILDLINK_PKGSRCDIR.mailimporter?=	../../mail/mailimporter

.include "../../misc/pimcommon/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# MAILIMPORTER_BUILDLINK3_MK

BUILDLINK_TREE+=	-mailimporter
