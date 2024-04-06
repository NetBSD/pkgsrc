# $NetBSD: buildlink3.mk,v 1.49 2024/04/06 08:05:03 wiz Exp $

BUILDLINK_TREE+=	knotifyconfig

.if !defined(KNOTIFYCONFIG_BUILDLINK3_MK)
KNOTIFYCONFIG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.knotifyconfig+=	knotifyconfig>=5.21.0
BUILDLINK_ABI_DEPENDS.knotifyconfig?=	knotifyconfig>=5.114.0nb1
BUILDLINK_PKGSRCDIR.knotifyconfig?=	../../devel/knotifyconfig

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KNOTIFYCONFIG_BUILDLINK3_MK

BUILDLINK_TREE+=	-knotifyconfig
