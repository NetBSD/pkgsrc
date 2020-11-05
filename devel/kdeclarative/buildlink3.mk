# $NetBSD: buildlink3.mk,v 1.28 2020/11/05 09:06:47 ryoon Exp $

BUILDLINK_TREE+=	kdeclarative

.if !defined(KDECLARATIVE_BUILDLINK3_MK)
KDECLARATIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdeclarative+=	kdeclarative>=5.21.0
BUILDLINK_ABI_DEPENDS.kdeclarative?=	kdeclarative>=5.70.0nb3
BUILDLINK_PKGSRCDIR.kdeclarative?=	../../devel/kdeclarative

.include "../../graphics/libepoxy/buildlink3.mk"
.include "../../devel/kio/buildlink3.mk"
.include "../../devel/kpackage/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KDECLARATIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdeclarative
