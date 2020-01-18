# $NetBSD: buildlink3.mk,v 1.2 2020/01/18 21:48:15 jperkin Exp $

BUILDLINK_TREE+=	kmime

.if !defined(KMIME_BUILDLINK3_MK)
KMIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kmime+=	kmime>=17.12.1
BUILDLINK_ABI_DEPENDS.kmime?=	kmime>=19.08.3nb1
BUILDLINK_PKGSRCDIR.kmime?=	../../mail/kmime

.include "../../devel/ki18n/buildlink3.mk"
.include "../../textproc/kcodecs/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KMIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-kmime
