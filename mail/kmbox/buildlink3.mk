# $NetBSD: buildlink3.mk,v 1.30 2026/09/06 11:02:55 markd Exp $

BUILDLINK_TREE+=	kmbox

.if !defined(KMBOX_BUILDLINK3_MK)
KMBOX_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kmbox+=	kmbox>=25.08.2
BUILDLINK_ABI_DEPENDS.kmbox?=	kmbox>=26.08.0
BUILDLINK_PKGSRCDIR.kmbox?=	../../mail/kmbox

.include "../../mail/kf6-kmime/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KMBOX_BUILDLINK3_MK

BUILDLINK_TREE+=	-kmbox
