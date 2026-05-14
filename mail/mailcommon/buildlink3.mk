# $NetBSD: buildlink3.mk,v 1.19 2026/05/14 16:41:24 ryoon Exp $

BUILDLINK_TREE+=	mailcommon

.if !defined(MAILCOMMON_BUILDLINK3_MK)
MAILCOMMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mailcommon+=	mailcommon>=25.08.3
BUILDLINK_ABI_DEPENDS.mailcommon?=	mailcommon>=25.08.3nb4
BUILDLINK_PKGSRCDIR.mailcommon?=	../../mail/mailcommon

.include "../../mail/mailimporter/buildlink3.mk"
.include "../../net/messagelib/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# MAILCOMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-mailcommon
