# $NetBSD: buildlink3.mk,v 1.1 2021/03/17 22:33:37 markd Exp $

BUILDLINK_TREE+=	purpose

.if !defined(PURPOSE_BUILDLINK3_MK)
PURPOSE_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.purpose+=	purpose>=5.70.0
BUILDLINK_PKGSRCDIR.purpose?=	../../wip/purpose

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/kirigami2/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# PURPOSE_BUILDLINK3_MK

BUILDLINK_TREE+=	-purpose
