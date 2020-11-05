# $NetBSD: buildlink3.mk,v 1.14 2020/11/05 09:06:56 ryoon Exp $

BUILDLINK_TREE+=	prison

.if !defined(PRISON_BUILDLINK3_MK)
PRISON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.prison+=	prison>=5.41.0
BUILDLINK_ABI_DEPENDS.prison?=	prison>=5.70.0nb2
BUILDLINK_PKGSRCDIR.prison?=	../../graphics/prison

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# PRISON_BUILDLINK3_MK

BUILDLINK_TREE+=	-prison
