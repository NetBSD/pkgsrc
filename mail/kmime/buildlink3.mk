# $NetBSD: buildlink3.mk,v 1.19 2024/11/01 00:52:34 wiz Exp $

BUILDLINK_TREE+=	kmime

.if !defined(KMIME_BUILDLINK3_MK)
KMIME_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kmime+=	kmime>=17.12.1
BUILDLINK_ABI_DEPENDS.kmime?=	kmime>=23.08.4nb3
BUILDLINK_PKGSRCDIR.kmime?=	../../mail/kmime

.include "../../devel/ki18n/buildlink3.mk"
.include "../../textproc/kcodecs/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KMIME_BUILDLINK3_MK

BUILDLINK_TREE+=	-kmime
