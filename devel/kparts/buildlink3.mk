# $NetBSD: buildlink3.mk,v 1.28 2020/11/05 09:06:48 ryoon Exp $

BUILDLINK_TREE+=	kparts

.if !defined(KPARTS_BUILDLINK3_MK)
KPARTS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kparts+=	kparts>=5.21.0
BUILDLINK_ABI_DEPENDS.kparts?=	kparts>=5.70.0nb3
BUILDLINK_PKGSRCDIR.kparts?=	../../devel/kparts

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KPARTS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kparts
