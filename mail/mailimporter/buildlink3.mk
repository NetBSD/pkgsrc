# $NetBSD: buildlink3.mk,v 1.19 2026/05/14 16:41:25 ryoon Exp $

BUILDLINK_TREE+=	mailimporter

.if !defined(MAILIMPORTER_BUILDLINK3_MK)
MAILIMPORTER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mailimporter+=	mailimporter>=25.08.3
BUILDLINK_ABI_DEPENDS.mailimporter?=	mailimporter>=25.08.3nb4
BUILDLINK_PKGSRCDIR.mailimporter?=	../../mail/mailimporter

.include "../../misc/pimcommon/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# MAILIMPORTER_BUILDLINK3_MK

BUILDLINK_TREE+=	-mailimporter
