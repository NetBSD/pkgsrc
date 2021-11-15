# $NetBSD: buildlink3.mk,v 1.2 2021/11/15 22:53:59 wiz Exp $

BUILDLINK_TREE+=	kmediaplayer

.if !defined(KMEDIAPLAYER_BUILDLINK3_MK)
KMEDIAPLAYER_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kmediaplayer+=	kmediaplayer>=5.80.0
BUILDLINK_ABI_DEPENDS.kmediaplayer?=	kmediaplayer>=5.80.0nb1
BUILDLINK_PKGSRCDIR.kmediaplayer?=	../../multimedia/kmediaplayer

.include "../../devel/kparts/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KMEDIAPLAYER_BUILDLINK3_MK

BUILDLINK_TREE+=	-kmediaplayer
