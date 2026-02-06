# $NetBSD: buildlink3.mk,v 1.27 2026/02/06 10:05:12 wiz Exp $

BUILDLINK_TREE+=	kmime

.if !defined(KMIME_BUILDLINK3_MK)
KMIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kmime+=	kmime>=25.08.2
BUILDLINK_ABI_DEPENDS.kmime?=	kmime>=25.08.3nb2
BUILDLINK_PKGSRCDIR.kmime?=	../../mail/kmime

.include "../../devel/kf6-ki18n/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../textproc/kf6-kcodecs/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.endif	# KMIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-kmime
