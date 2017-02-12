# $NetBSD: buildlink3.mk,v 1.6 2017/02/12 06:24:38 ryoon Exp $

BUILDLINK_TREE+=	kcmutils

.if !defined(KCMUTILS_BUILDLINK3_MK)
KCMUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kcmutils+=	kcmutils>=5.21.0
BUILDLINK_ABI_DEPENDS.kcmutils?=	kcmutils>=5.25.0nb4
BUILDLINK_PKGSRCDIR.kcmutils?=	../../devel/kcmutils

.include "../../devel/kdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KCMUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kcmutils
