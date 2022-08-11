# $NetBSD: buildlink3.mk,v 1.38 2022/08/11 05:08:10 gutteridge Exp $

BUILDLINK_TREE+=	knotifyconfig

.if !defined(KNOTIFYCONFIG_BUILDLINK3_MK)
KNOTIFYCONFIG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.knotifyconfig+=	knotifyconfig>=5.21.0
BUILDLINK_ABI_DEPENDS.knotifyconfig?=	knotifyconfig>=5.93.0nb2
BUILDLINK_PKGSRCDIR.knotifyconfig?=	../../devel/knotifyconfig

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KNOTIFYCONFIG_BUILDLINK3_MK

BUILDLINK_TREE+=	-knotifyconfig
