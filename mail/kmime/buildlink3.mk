# $NetBSD: buildlink3.mk,v 1.11 2022/11/23 16:18:51 adam Exp $

BUILDLINK_TREE+=	kmime

.if !defined(KMIME_BUILDLINK3_MK)
KMIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kmime+=	kmime>=17.12.1
BUILDLINK_ABI_DEPENDS.kmime?=	kmime>=22.08.1nb1
BUILDLINK_PKGSRCDIR.kmime?=	../../mail/kmime

.include "../../devel/ki18n/buildlink3.mk"
.include "../../textproc/kcodecs/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KMIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-kmime
