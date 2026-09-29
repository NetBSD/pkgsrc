# $NetBSD: buildlink3.mk,v 1.24 2026/09/29 06:06:23 wiz Exp $

BUILDLINK_TREE+=	mailcommon

.if !defined(MAILCOMMON_BUILDLINK3_MK)
MAILCOMMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mailcommon+=	mailcommon>=25.08.3
BUILDLINK_ABI_DEPENDS.mailcommon?=	mailcommon>=26.08.0nb2
BUILDLINK_PKGSRCDIR.mailcommon?=	../../mail/mailcommon

.include "../../mail/mailimporter/buildlink3.mk"
.include "../../net/messagelib/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# MAILCOMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-mailcommon
