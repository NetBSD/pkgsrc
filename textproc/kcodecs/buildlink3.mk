# $NetBSD: buildlink3.mk,v 1.3 2017/02/06 13:54:51 wiz Exp $

BUILDLINK_TREE+=	kcodecs

.if !defined(KCODECS_BUILDLINK3_MK)
KCODECS_BUILDLINK3_MK:=

BUILDLINK_API_DEPENDS.kcodecs+=	kcodecs>=5.18.0
BUILDLINK_ABI_DEPENDS.kcodecs?=	kcodecs>=5.25.0nb3
BUILDLINK_PKGSRCDIR.kcodecs?=	../../textproc/kcodecs

.include "../../x11/qt5-qtbase/buildlink3.mk"
.endif	# KCODECS_BUILDLINK3_MK

BUILDLINK_TREE+=	-kcodecs
