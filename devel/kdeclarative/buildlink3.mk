# $NetBSD: buildlink3.mk,v 1.24 2020/04/12 08:27:51 adam Exp $

BUILDLINK_TREE+=	kdeclarative

.if !defined(KDECLARATIVE_BUILDLINK3_MK)
KDECLARATIVE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kdeclarative+=	kdeclarative>=5.21.0
BUILDLINK_ABI_DEPENDS.kdeclarative?=	kdeclarative>=5.66.0nb3
BUILDLINK_PKGSRCDIR.kdeclarative?=	../../devel/kdeclarative

.include "../../graphics/libepoxy/buildlink3.mk"
.include "../../devel/kio/buildlink3.mk"
.include "../../devel/kpackage/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KDECLARATIVE_BUILDLINK3_MK

BUILDLINK_TREE+=	-kdeclarative
