# $NetBSD: buildlink3.mk,v 1.18 2024/04/06 08:06:08 wiz Exp $

BUILDLINK_TREE+=	kmbox

.if !defined(KMBOX_BUILDLINK3_MK)
KMBOX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kmbox+=	kmbox>=17.12.1
BUILDLINK_ABI_DEPENDS.kmbox?=	kmbox>=23.08.4nb1
BUILDLINK_PKGSRCDIR.kmbox?=	../../mail/kmbox

.include "../../mail/kmime/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KMBOX_BUILDLINK3_MK

BUILDLINK_TREE+=	-kmbox
