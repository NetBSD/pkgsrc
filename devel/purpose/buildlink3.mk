# $NetBSD: buildlink3.mk,v 1.23 2024/11/01 12:52:19 wiz Exp $

BUILDLINK_TREE+=	purpose

.if !defined(PURPOSE_BUILDLINK3_MK)
PURPOSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.purpose+=	purpose>=5.70.0
BUILDLINK_ABI_DEPENDS.purpose?=	purpose>=5.116.0nb3
BUILDLINK_PKGSRCDIR.purpose?=	../../devel/purpose

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/kirigami2/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# PURPOSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-purpose
