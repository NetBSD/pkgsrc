# $NetBSD: buildlink3.mk,v 1.26 2026/01/07 08:47:46 wiz Exp $

BUILDLINK_TREE+=	kmbox

.if !defined(KMBOX_BUILDLINK3_MK)
KMBOX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kmbox+=	kmbox>=25.08.2
BUILDLINK_ABI_DEPENDS.kmbox?=	kmbox>=25.08.3nb1
BUILDLINK_PKGSRCDIR.kmbox?=	../../mail/kmbox

.include "../../mail/kmime/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KMBOX_BUILDLINK3_MK

BUILDLINK_TREE+=	-kmbox
