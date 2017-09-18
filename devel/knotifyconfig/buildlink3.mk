# $NetBSD: buildlink3.mk,v 1.11 2017/09/18 09:52:59 maya Exp $

BUILDLINK_TREE+=	knotifyconfig

.if !defined(KNOTIFYCONFIG_BUILDLINK3_MK)
KNOTIFYCONFIG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.knotifyconfig+=	knotifyconfig>=5.21.0
BUILDLINK_ABI_DEPENDS.knotifyconfig?=	knotifyconfig>=5.25.0nb10
BUILDLINK_PKGSRCDIR.knotifyconfig?=	../../devel/knotifyconfig

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KNOTIFYCONFIG_BUILDLINK3_MK

BUILDLINK_TREE+=	-knotifyconfig
