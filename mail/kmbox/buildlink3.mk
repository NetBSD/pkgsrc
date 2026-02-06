# $NetBSD: buildlink3.mk,v 1.27 2026/02/06 10:05:12 wiz Exp $

BUILDLINK_TREE+=	kmbox

.if !defined(KMBOX_BUILDLINK3_MK)
KMBOX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kmbox+=	kmbox>=25.08.2
BUILDLINK_ABI_DEPENDS.kmbox?=	kmbox>=25.08.3nb2
BUILDLINK_PKGSRCDIR.kmbox?=	../../mail/kmbox

.include "../../mail/kmime/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KMBOX_BUILDLINK3_MK

BUILDLINK_TREE+=	-kmbox
