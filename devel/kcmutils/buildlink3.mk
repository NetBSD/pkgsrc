# $NetBSD: buildlink3.mk,v 1.36 2022/03/28 10:52:59 tnn Exp $

BUILDLINK_TREE+=	kcmutils

.if !defined(KCMUTILS_BUILDLINK3_MK)
KCMUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kcmutils+=	kcmutils>=5.21.0
BUILDLINK_ABI_DEPENDS.kcmutils?=	kcmutils>=5.80.0nb5
BUILDLINK_PKGSRCDIR.kcmutils?=		../../devel/kcmutils

.include "../../devel/kdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KCMUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kcmutils
