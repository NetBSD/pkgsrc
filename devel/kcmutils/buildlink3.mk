# $NetBSD: buildlink3.mk,v 1.3 2016/12/04 05:17:05 ryoon Exp $

BUILDLINK_TREE+=	kcmutils

.if !defined(KCMUTILS_BUILDLINK3_MK)
KCMUTILS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kcmutils+=	kcmutils>=5.21.0
BUILDLINK_ABI_DEPENDS.kcmutils?=	kcmutils>=5.25.0nb1
BUILDLINK_PKGSRCDIR.kcmutils?=	../../devel/kcmutils

.include "../../devel/kdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KCMUTILS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kcmutils
