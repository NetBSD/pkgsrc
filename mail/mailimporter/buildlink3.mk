# $NetBSD: buildlink3.mk,v 1.3 2023/11/08 13:19:57 wiz Exp $

BUILDLINK_TREE+=	mailimporter

.if !defined(MAILIMPORTER_BUILDLINK3_MK)
MAILIMPORTER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.mailimporter+=	mailimporter>=20.04.1
BUILDLINK_ABI_DEPENDS.mailimporter?=	mailimporter>=23.04.3nb2
BUILDLINK_PKGSRCDIR.mailimporter?=	../../mail/mailimporter

.include "../../misc/pimcommon/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# MAILIMPORTER_BUILDLINK3_MK

BUILDLINK_TREE+=	-mailimporter
