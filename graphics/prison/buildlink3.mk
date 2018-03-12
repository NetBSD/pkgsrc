# $NetBSD: buildlink3.mk,v 1.2 2018/03/12 11:15:37 wiz Exp $

BUILDLINK_TREE+=	prison

.if !defined(PRISON_BUILDLINK3_MK)
PRISON_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.prison+=	prison>=5.41.0
BUILDLINK_ABI_DEPENDS.prison?=	prison>=5.41.0nb1
BUILDLINK_PKGSRCDIR.prison?=	../../graphics/prison

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# PRISON_BUILDLINK3_MK

BUILDLINK_TREE+=	-prison
