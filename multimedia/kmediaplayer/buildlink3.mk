# $NetBSD: buildlink3.mk,v 1.10 2023/04/19 08:08:33 adam Exp $

BUILDLINK_TREE+=	kmediaplayer

.if !defined(KMEDIAPLAYER_BUILDLINK3_MK)
KMEDIAPLAYER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kmediaplayer+=	kmediaplayer>=5.80.0
BUILDLINK_ABI_DEPENDS.kmediaplayer?=	kmediaplayer>=5.98.0nb4
BUILDLINK_PKGSRCDIR.kmediaplayer?=	../../multimedia/kmediaplayer

.include "../../devel/kparts/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KMEDIAPLAYER_BUILDLINK3_MK

BUILDLINK_TREE+=	-kmediaplayer
