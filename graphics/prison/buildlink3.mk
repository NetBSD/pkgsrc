# $NetBSD: buildlink3.mk,v 1.29 2025/04/24 14:14:35 wiz Exp $

BUILDLINK_TREE+=	prison

.if !defined(PRISON_BUILDLINK3_MK)
PRISON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.prison+=	prison>=5.41.0
BUILDLINK_ABI_DEPENDS.prison?=	prison>=5.116.0nb6
BUILDLINK_PKGSRCDIR.prison?=	../../graphics/prison

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# PRISON_BUILDLINK3_MK

BUILDLINK_TREE+=	-prison
