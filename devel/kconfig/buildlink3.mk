# $NetBSD: buildlink3.mk,v 1.6 2017/09/18 09:52:58 maya Exp $

BUILDLINK_TREE+=	kconfig

.if !defined(KCONFIG_BUILDLINK3_MK)
KCONFIG_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kconfig+=	kconfig>=5.18.0
BUILDLINK_ABI_DEPENDS.kconfig?=	kconfig>=5.25.0nb9
BUILDLINK_PKGSRCDIR.kconfig?=	../../devel/kconfig

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KCONFIG_BUILDLINK3_MK

BUILDLINK_TREE+=	-kconfig
