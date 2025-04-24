# $NetBSD: buildlink3.mk,v 1.13 2025/04/24 14:14:57 wiz Exp $

BUILDLINK_TREE+=	mailcommon

.if !defined(MAILCOMMON_BUILDLINK3_MK)
MAILCOMMON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mailcommon+=	mailcommon>=20.04.1
BUILDLINK_ABI_DEPENDS.mailcommon?=	mailcommon>=23.08.4nb9
BUILDLINK_PKGSRCDIR.mailcommon?=	../../mail/mailcommon

.include "../../mail/mailimporter/buildlink3.mk"
.include "../../net/messagelib/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# MAILCOMMON_BUILDLINK3_MK

BUILDLINK_TREE+=	-mailcommon
