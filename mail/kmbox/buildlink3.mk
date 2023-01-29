# $NetBSD: buildlink3.mk,v 1.12 2023/01/29 21:14:48 ryoon Exp $

BUILDLINK_TREE+=	kmbox

.if !defined(KMBOX_BUILDLINK3_MK)
KMBOX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kmbox+=	kmbox>=17.12.1
BUILDLINK_ABI_DEPENDS.kmbox?=	kmbox>=22.08.1nb2
BUILDLINK_PKGSRCDIR.kmbox?=	../../mail/kmbox

.include "../../mail/kmime/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KMBOX_BUILDLINK3_MK

BUILDLINK_TREE+=	-kmbox
