# $NetBSD: buildlink3.mk,v 1.36 2025/04/17 21:50:27 wiz Exp $

BUILDLINK_TREE+=	kross

.if !defined(KROSS_BUILDLINK3_MK)
KROSS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kross+=	kross>=5.64.0
BUILDLINK_ABI_DEPENDS.kross?=	kross>=5.116.0nb6
BUILDLINK_PKGSRCDIR.kross?=	../../devel/kross

.include "../../devel/kparts/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtscript/buildlink3.mk"
.endif	# KROSS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kross
