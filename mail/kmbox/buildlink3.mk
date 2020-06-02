# $NetBSD: buildlink3.mk,v 1.6 2020/06/02 08:22:47 adam Exp $

BUILDLINK_TREE+=	kmbox

.if !defined(KMBOX_BUILDLINK3_MK)
KMBOX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kmbox+=	kmbox>=17.12.1
BUILDLINK_ABI_DEPENDS.kmbox?=	kmbox>=19.12.1nb4
BUILDLINK_PKGSRCDIR.kmbox?=	../../mail/kmbox

.include "../../mail/kmime/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KMBOX_BUILDLINK3_MK

BUILDLINK_TREE+=	-kmbox
