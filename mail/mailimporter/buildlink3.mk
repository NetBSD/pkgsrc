# $NetBSD: buildlink3.mk,v 1.6 2024/04/06 08:06:09 wiz Exp $

BUILDLINK_TREE+=	mailimporter

.if !defined(MAILIMPORTER_BUILDLINK3_MK)
MAILIMPORTER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mailimporter+=	mailimporter>=20.04.1
BUILDLINK_ABI_DEPENDS.mailimporter?=	mailimporter>=23.08.4nb1
BUILDLINK_PKGSRCDIR.mailimporter?=	../../mail/mailimporter

.include "../../misc/pimcommon/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# MAILIMPORTER_BUILDLINK3_MK

BUILDLINK_TREE+=	-mailimporter
